#include "VCPXpress.h"
#include "descriptor.h"
#include <SI_EFM8UB1_Register_Enums.h>



//-----------------------------------------------------------------------------
// USB_Detect_Charger
//-----------------------------------------------------------------------------
//
// Description - Detect charger type and return it to caller.
//
//-----------------------------------------------------------------------------


SI_SBIT(BSP_VBUS, SFR_P3, 1);

static uint8_t
USB_Detect_Charger (void)
{
  uint8_t sfrPageSave = SFRPAGE;
  uint8_t ret = 0;

  if (BSP_VBUS == 0)
    {
      return ret;
    }

  SFRPAGE = PG3_PAGE;

  USB0CDSTA = 0;

  // Enable charger detection using primary detection and data contact detection
  USB0CDCN = USB0CDCN_CHDEN__ENABLED | USB0CDCN_PDEN__ENABLED
      | USB0CDCN_DCDEN__ENABLED;

  /* Wait for primary detection to complete */
  while ((USB0CDSTA & USB0CDSTA_PDI__SET) == 0)
    ;

  /* SDP bit will indicate if a Standard Downstream Port is detected */
  if (USB0CDSTA &USB0CDSTA_SDP__DETECTED)
    {
      ret = 1;
    }
  else
    {
      USB0CDSTA = 0;

      /* Do Secondary Detection for DCP and CDP */
      USB0CDCN = USB0CDCN_CHDEN__ENABLED | USB0CDCN_SDEN__ENABLED;

      /* Wait for Secondary Detection to complete */
      while ((USB0CDSTA & USB0CDSTA_SDI__SET) == 0)
        ;

      if (USB0CDSTA &USB0CDSTA_CDP__DETECTED)
        {
          ret = 0;
        }
      else if (USB0CDSTA &USB0CDSTA_DCP__DETECTED)
        {
          ret = 0;
        }
    }

  SFRPAGE = sfrPageSave;

  return ret;
}


void check_and_initialize_USB(){
  if (USB_Detect_Charger ())
    {
      USB_Init (&InitStruct);
      API_Callback_Enable ();
    }
}




void
VCP_Callback (void)
{

}

