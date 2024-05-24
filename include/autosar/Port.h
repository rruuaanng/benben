#ifndef BENBEN_AUTOSAR_PORT_H
#define BENBEN_AUTOSAR_PORT_H

#include <autosar/Std_Types.h>
#include <autosar/cfg.h>


// [SWS_Port_00051] Definiton of development errors in module Port
#define PORT_E_PARAM_PIN                        0x0A
#define PORT_E_DIRECTION_UNCHANGEABLE           0x0B
#define PORT_E_INIT_FAILED                      0x0C
#define PORT_E_PARAM_INVALID_MODE               0x0D
#define PORT_E_MODE_UNCHANGEABLE                0x0E
#define PORT_E_UNINIT                           0x0F
#define PORT_E_PARAM_POINTER                    0x10


// [SWS_Port_00228] Definition of datatype Port_ConfigType
// Name:            Port_ConfigType
// Kind:            Structure
// Element:         Hardware Dependent Structure
// Description:     Type of the external data structure containing 
//                  the initialization data for this module
typedef struct {
    char name[32];
    void *info;
}Port_ConfigType;


// [SWS_Port_00229] Definition of datatype Port_PinType
// Name:            Port_PinType
// Kind:            type
// Derived from:    uint
// Range:           0-N
// Description:     Data type for the symbolic name of a port pin
#if PORT_PORTPIN_SIZE == 0U
typedef uint8_t Port_PinType;
#elif PORT_PORTPIN_SIZE == 1U
typedef uint16_t Port_PinType;
#elif PORT_PORTPIN_SIZE == 2U
typedef uint32_t Port_PinType;
#else   
typedef uint32_t Port_PinType;  /* default 32bit */
#endif // Port_PinType


// [SWS_Port_00230] Definition of datatype Port_PinDirectionType
// Name:            Port_Pin_DirectionType
// Kind:            Enumeration
// Range:           PORT_PIN_IN
//                  PORT_PIN_OUT
// Description:     Possible directions of a port pin
typedef enum {
    PORT_PIN_IN = 0x00, /* sets port pin as input */
    PORT_PIN_OUT = 0x01 /* sets port pin as output */
}Port_PinDirectionType;


// [SWS_Port_00231] Definition of datatype Port_PinModeType
// Name:            Port_PinModeType
// Kind:            type
// Derived from:    uint
// Range:           implementation specific
// Description:     Different port pin modes
#if PORT_PINMODE_SIZE == 0U
typedef uint8_t Port_PinModeType;
#elif PORT_PINMODE_SIZE == 1U
typedef uint16_t Port_PinModeType;
#elif PORT_PINMODE_SIZE == 2U
typedef uint32_t Port_PinModeType;
#else
typedef uint32_t Port_PinModeType; /* default 32bit */
#endif // Port_PinType


// [SWS_Port_00140] Definition of API function Port_Init
// Service Name:            Port_Init
// Service ID:              0x00
// Sync/Async:              Synchronous
// Reentrancy:              Non Reentrant
// Parameters(in):          ConfigPtr
// Parameters(inout):       None
// Parameters(out):         None
// Return Value:            None
// Description:             Initalizes the Port Driver module
void Port_Init(
    const Port_ConfigType *ConfigPtr
);


// [SWS_Port_00141] Definition of API function Port_SetPinDirection
// Service Name:            Port_SetPinDirection
// Service ID:              0x01
// Sync/Async:              Synchronous
// Reentrancy:              Reentrant
// Parameters(in):          Pin
//                          Direction
// Parameters(inout):       None
// Parameters(out):         None
// Return Value:            None
// Description:             Sets the port pin direction
void Port_SetPinDirection(
    Port_PinType Pin,
    Port_PinDirectionType Direction
);


// [SWS_Port_00142] Definition of API function Port_RefreshPortDirection
// Service Name:            Port_RefreshPortDirection
// Service ID:              0x02
// Sync/Async:              Synchronous
// Reentrancy:              NonReentrant
// Parameters(in):          None
// Parameters(inout):       None
// Parameters(out):         None
// Return Value:            None
// Description:             Refreshes port direction
void Port_RefreshPortDirection(
    void
);


// [SWS_Port_00143] Definition of API function Port_GetVersionInfo
// Service Name:            Port_GetVersionInfo
// Service ID:              0x03
// Sync/Async:              Synchronous
// Reentrancy:              Reentrant
// Parameters(in):          None
// Parameters(inout):       None
// Parameters(out):         versioninfo
// Return Value:            None
// Description:             Returns the version information of this module
void Port_GetVersionInfo(
    Std_VersionInfoType *versioninfo
);


// [SWS_Port_00145] Definition of API function Port_SetPinMode
// Service Name:            Port_SetPinMode
// Service ID:              0x04
// Sync/Async:              Synchronous
// Reentrancy:              Reentrant
// Parameters(in):          Pin
//                          Mode
// Parameters(inout):       None
// Parameters(out):         None
// Return Value:            None
// Description:             Sets the port pin mode
void Port_SetPinMode(
    Port_PinType Pin,
    Port_PinModeType Mode
);

#endif // BENBEN_AUTOSAR_PORT_H