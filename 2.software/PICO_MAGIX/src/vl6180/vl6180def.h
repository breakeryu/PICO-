#ifndef VL6180DEF_H_
#define VL6180DEF_H_

#include "Arduino.h"



#define VL6180X_IDENTIFICATION_MODEL_ID 0x0000
#define VL6180X_IDENTIFICATION_MODEL_REV_MAJOR 0x0001
#define VL6180X_IDENTIFICATION_MODEL_REV_MINOR 0x0002
#define VL6180X_IDENTIFICATION_MODULE_REV_MAJOR 0x0003
#define VL6180X_IDENTIFICATION_MODULE_REV_MINOR 0x0004
#define VL6180X_IDENTIFICATION_DATE 0x0006 // 16bit value
#define VL6180X_IDENTIFICATION_TIME 0x0008 // 16bit value


#define VL6180X_SYSTEM_MODE_GPIO0 0x0010
#define VL6180X_SYSTEM_MODE_GPIO1 0x0011
#define VL6180X_SYSTEM_HISTORY_CTRL 0x0012
#define VL6180X_SYSTEM_INTERRUPT_CONFIG_GPIO 0x0014
#define VL6180X_SYSTEM_INTERRUPT_CLEAR 0x0015
#define VL6180X_SYSTEM_FRESH_OUT_OF_RESET 0x0016
#define VL6180X_SYSTEM_GROUPED_PARAMETER_HOLD 0x0017

#define VL6180X_SYSRANGE_START 0x0018
#define VL6180X_SYSRANGE_THRESH_HIGH 0x0019
#define VL6180X_SYSRANGE_THRESH_LOW 0x001A
#define VL6180X_SYSRANGE_INTERMEASUREMENT_PERIOD 0x001B
#define VL6180X_SYSRANGE_MAX_CONVERGENCE_TIME 0x001C
#define VL6180X_SYSRANGE_CROSSTALK_COMPENSATION_RATE 0x001E
#define VL6180X_SYSRANGE_CROSSTALK_VALID_HEIGHT 0x0021
#define VL6180X_SYSRANGE_EARLY_CONVERGENCE_ESTIMATE 0x0022
#define VL6180X_SYSRANGE_PART_TO_PART_RANGE_OFFSET 0x0024
#define VL6180X_SYSRANGE_RANGE_IGNORE_VALID_HEIGHT 0x0025
#define VL6180X_SYSRANGE_RANGE_IGNORE_THRESHOLD 0x0026
#define VL6180X_SYSRANGE_MAX_AMBIENT_LEVEL_MULT 0x002C
#define VL6180X_SYSRANGE_RANGE_CHECK_ENABLES 0x002D
#define VL6180X_SYSRANGE_VHV_RECALIBRATE 0x002E
#define VL6180X_SYSRANGE_VHV_REPEAT_RATE 0x0031

#define VL6180X_SYSALS_START 0x0038
#define VL6180X_SYSALS_THRESH_HIGH 0x003A
#define VL6180X_SYSALS_THRESH_LOW 0x003C
#define VL6180X_SYSALS_INTERMEASUREMENT_PERIOD 0x003E
#define VL6180X_SYSALS_ANALOGUE_GAIN 0x003F
#define VL6180X_SYSALS_INTEGRATION_PERIOD 0x0040

#define VL6180X_RESULT_RANGE_STATUS 0x004D
#define VL6180X_RESULT_ALS_STATUS 0x004E
#define VL6180X_RESULT_INTERRUPT_STATUS_GPIO 0x004F
#define VL6180X_RESULT_ALS_VAL 0x0050
#define VL6180X_RESULT_HISTORY_BUFFER 0x0052
#define VL6180X_RESULT_RANGE_VAL 0x0062
#define VL6180X_RESULT_RANGE_RAW 0x0064
#define VL6180X_RESULT_RANGE_RETURN_RATE 0x0066
#define VL6180X_RESULT_RANGE_REFERENCE_RATE 0x0068
#define VL6180X_RESULT_RANGE_RETURN_SIGNAL_COUNT 0x006C
#define VL6180X_RESULT_RANGE_REFERENCE_SIGNAL_COUNT 0x0070
#define VL6180X_RESULT_RANGE_RETURN_AMB_COUNT 0x0074
#define VL6180X_RESULT_RANGE_REFERENCE_AMB_COUNT 0x0078
#define VL6180X_RESULT_RANGE_RETURN_CONV_TIME 0x007C
#define VL6180X_RESULT_RANGE_REFERENCE_CONV_TIME 0x0080

#define VL6180X_READOUT_AVERAGING_SAMPLE_PERIOD 0x010A
#define VL6180X_FIRMWARE_BOOTUP 0x0119
#define VL6180X_FIRMWARE_RESULT_SCALER 0x0120
#define VL6180X_I2C_SLAVE_DEVICE_ADDRESS 0x0212
#define VL6180X_INTERLEAVED_MODE_ENABLE 0x02A3



/** @ingroup device_regdef
 * @{*/

/**
 * The device model ID
 */
#define IDENTIFICATION_MODEL_ID                 0x000
/**
 * Revision identifier of the Device for major change.
 */
#define IDENTIFICATION_MODULE_REV_MAJOR         0x003
/**
 * Revision identifier of the Device for minor change.
 */
#define IDENTIFICATION_MODULE_REV_MINOR         0x004


/**
 * @def SYSTEM_MODE_GPIO0
 * @brief Configures polarity and select which function gpio 0 serves.
 *  Gpio0 is chip enable at power up ! Be aware of all h/w implication of turning it to output.
 *  Same definition as #SYSTEM_MODE_GPIO1
 * @ingroup device_regdef
 */
#define SYSTEM_MODE_GPIO0                       0x010
/**
 * @def SYSTEM_MODE_GPIO1
 * @brief Configures polarity and select what als or ranging functionality gpio pin serves.
 *
 * Function can be #GPIOx_SELECT_OFF  #GPIOx_SELECT_GPIO_INTERRUPT_OUTPUT.\n
 * Same definition apply to register GPIO0 that is used as chip enable at power up.
 * @ingroup device_regdef
 */
#define SYSTEM_MODE_GPIO1                       0x011
    /** gpio pad POLARITY mask in #SYSTEM_MODE_GPIO1 (and/or 0) write  1  to set active high polarity (positive edge) */
    #define GPIOx_POLARITY_SELECT_MASK              0x20
    /** gpio pad Function select shift in #SYSTEM_MODE_GPIO1 or 0 */
    #define GPIOx_FUNCTIONALITY_SELECT_SHIFT          1
    /** gpio pad Function select mask in #SYSTEM_MODE_GPIO1 or 0 */
    #define GPIOx_FUNCTIONALITY_SELECT_MASK          (0xF<<GPIOx_FUNCTIONALITY_SELECT_SHIFT)
    /** select no interrupt in #SYSTEM_MODE_GPIO1 pad is put in  Hi-Z*/
    #define GPIOx_SELECT_OFF                        0x00
    /** select gpiox as interrupt output in  #SYSTEM_MODE_GPIO1 */
    #define GPIOx_SELECT_GPIO_INTERRUPT_OUTPUT      0x08
    /** select range as source for interrupt on in #SYSTEM_MODE_GPIO1 */
    #define GPIOx_MODE_SELECT_RANGING               0x00
    /** select als as source for interrupt on in #SYSTEM_MODE_GPIO1 */
    #define GPIOx_MODE_SELECT_ALS                   0x01


/**
 * @def SYSTEM_INTERRUPT_CONFIG_GPIO
 *
 * @brief   Configure Als and Ranging interrupt reporting
 *
 * Possible values for Range and ALS are\n
 *
 * #CONFIG_GPIO_INTERRUPT_DISABLED\n
 * #CONFIG_GPIO_INTERRUPT_LEVEL_LOW\n
 * #CONFIG_GPIO_INTERRUPT_LEVEL_HIGH\n
 * #CONFIG_GPIO_INTERRUPT_OUT_OF_WINDOW\n
 * #CONFIG_GPIO_INTERRUPT_NEW_SAMPLE_READY\n
 * Apply respective rang/als shift and mask \n
 *  #CONFIG_GPIO_RANGE_SHIFT and full reg mask #CONFIG_GPIO_RANGE_MASK\n
 *  #CONFIG_GPIO_ALS_SHIFT and full reg mask #CONFIG_GPIO_ALS_MASK\n
 *
 * \sa GPIO use for interrupt #SYSTEM_MODE_GPIO0 or #SYSTEM_MODE_GPIO1\n
 * @ingroup device_regdef
 */
#define SYSTEM_INTERRUPT_CONFIG_GPIO           0x014
    /** RANGE bits shift in #SYSTEM_INTERRUPT_CONFIG_GPIO */
    #define CONFIG_GPIO_RANGE_SHIFT            0
    /** RANGE bits mask in #SYSTEM_INTERRUPT_CONFIG_GPIO  (unshifted)*/
    #define CONFIG_GPIO_RANGE_MASK             (0x7<<CONFIG_GPIO_RANGE_SHIFT)
    /** ALS bits shift in #SYSTEM_INTERRUPT_CONFIG_GPIO */
    #define CONFIG_GPIO_ALS_SHIFT              3
    /** ALS bits mask in #SYSTEM_INTERRUPT_CONFIG_GPIO  (unshifted)*/
    #define CONFIG_GPIO_ALS_MASK               (0x7<<CONFIG_GPIO_ALS_SHIFT)
    /** interrupt is disabled */
    #define CONFIG_GPIO_INTERRUPT_DISABLED         0x00
    /** trigger when value < low threshold */
    #define CONFIG_GPIO_INTERRUPT_LEVEL_LOW        0x01
    /** trigger when value < low threshold */
    #define CONFIG_GPIO_INTERRUPT_LEVEL_HIGH       0x02
    /** trigger when outside range defined by high low threshold */
    #define CONFIG_GPIO_INTERRUPT_OUT_OF_WINDOW    0x03
    /** trigger when new sample are ready */
    #define CONFIG_GPIO_INTERRUPT_NEW_SAMPLE_READY 0x04

/**
 *  @def SYSTEM_INTERRUPT_CLEAR
 *  @brief Writing to this register will clear interrupt source
 *
 *  Use or combination of any #INTERRUPT_CLEAR_RANGING , #INTERRUPT_CLEAR_ALS , #INTERRUPT_CLEAR_ERROR
 *  @ingroup device_regdef
 */
#define SYSTEM_INTERRUPT_CLEAR                0x015
    /** clear ranging interrupt in write to #SYSTEM_INTERRUPT_CLEAR */
    #define INTERRUPT_CLEAR_RANGING                0x01
    /** clear als interrupt  in write to #SYSTEM_INTERRUPT_CLEAR */
    #define INTERRUPT_CLEAR_ALS                    0x02
    /** clear error interrupt in write to #SYSTEM_INTERRUPT_CLEAR */
    #define INTERRUPT_CLEAR_ERROR                  0x04

/** After power up or reset this register will start reading 1 when device is ready */
#define SYSTEM_FRESH_OUT_OF_RESET             0x016

/**
 * @def SYSTEM_GROUPED_PARAMETER_HOLD
 * @brief Writing 1/0 activate/deactivate safe host update of multiple register in critical group \n
 *        rather use \a VL6180x_SetGroupParamHold()
 *
 * The critical register group is made of: \n
 * #SYSTEM_INTERRUPT_CONFIG_GPIO \n
 * #SYSRANGE_THRESH_HIGH \n
 * #SYSRANGE_THRESH_LOW \n
 * #SYSALS_INTEGRATION_PERIOD \n
 * #SYSALS_ANALOGUE_GAIN \n
 * #SYSALS_THRESH_HIGH \n
 * #SYSALS_THRESH_LOW
 * @ingroup device_regdef
 */
#define SYSTEM_GROUPED_PARAMETER_HOLD         0x017


/**
 * @def SYSRANGE_START
 * @brief Start/stop and set operating range mode
 *
 * Write Combination of #MODE_START_STOP  and #MODE_CONTINUOUS to select and start desired operation.
 *
 * @ingroup device_regdef
 */
#define SYSRANGE_START                        0x018
    /** mask existing bit in #SYSRANGE_START*/
    #define SYSRANGE_START_MODE_MASK          0x03
    /** bit 0 in #SYSRANGE_START write 1 toggle state in continuous mode and arm next shot in single shot mode */
    #define MODE_START_STOP                   0x01
    /** bit 1 write 1 in #SYSRANGE_START set continuous operation mode */
    #define MODE_CONTINUOUS                   0x02
    /** bit 1 write 0 in #SYSRANGE_START set single shot mode */
    #define MODE_SINGLESHOT                   0x00

/**
 * @def SYSRANGE_THRESH_HIGH
 * High level range  threshold (must be scaled)
 * @ingroup device_regdef
 */
#define SYSRANGE_THRESH_HIGH                  0x019

/**
 * @def SYSRANGE_THRESH_LOW
 * Low level range  threshold (must be scaled)
 * @ingroup device_regdef
 */
#define SYSRANGE_THRESH_LOW                   0x01A

/**
 * @def SYSRANGE_INTERMEASUREMENT_PERIOD
 * @brief Continuous mode intermeasurement delay \a VL6180x_RangeSetInterMeasPeriod()
 *
 * Time delay between measurements in Ranging continuous mode.\n
 * Range 0-254 (0 = 10ms).\n Step size = 10ms.
 *
 * @ingroup device_regdef
 */
#define SYSRANGE_INTERMEASUREMENT_PERIOD      0x01B

/**
 * @brief Maximum time to run measurement in Ranging modes.
 * Range 1 - 63 ms (1 code = 1 ms);
 *
 * Measurement aborted when limit reached to aid power  reduction.\
 * For example, 0x01 = 1ms, 0x0a = 10ms.\
 * Note: Effective max_convergence_time depends on readout_averaging_sample_period setting.
 *
 * @ingroup device_regdef
 */
#define SYSRANGE_MAX_CONVERGENCE_TIME         0x01C
/**@brief Cross talk compensation rate
 * @warning  never write register directly use @a VL6180x_SetXTalkCompensationRate()
 * refer to manual for calibration procedure and computation
 * @ingroup device_regdef
 */
#define SYSRANGE_CROSSTALK_COMPENSATION_RATE  0x01E
/**
 * @brief Minimum range value in mm to qualify for crosstalk compensation
 */
#define SYSRANGE_CROSSTALK_VALID_HEIGHT       0x021
#define SYSRANGE_EARLY_CONVERGENCE_ESTIMATE   0x022
#define SYSRANGE_PART_TO_PART_RANGE_OFFSET    0x024
/**
 * @brief range ignore valid height
 * @warning  do not program directly use @a VL6180x_RangeIgnoreConfigure() and @a VL6180x_RangeIgnoreSetEnable()
 */
#define SYSRANGE_RANGE_IGNORE_VALID_HEIGHT    0x025
/**
 * @brief range ignore threshold
 * @warning  do not program directly use @a VL6180x_RangeIgnoreConfigure() and @a VL6180x_RangeIgnoreSetEnable()
 */
#define SYSRANGE_RANGE_IGNORE_THRESHOLD       0x026
#define SYSRANGE_EMITTER_BLOCK_THRESHOLD      0x028
#define SYSRANGE_MAX_AMBIENT_LEVEL_THRESH     0x02A
#define SYSRANGE_MAX_AMBIENT_LEVEL_MULT       0x02C
/** @brief  various Enable check enable register
 *  @a VL6180x_RangeSetEceState()
 *  @a VL6180x_RangeIgnoreConfigure() and @a VL6180x_RangeIgnoreSetEnable()
 */
#define SYSRANGE_RANGE_CHECK_ENABLES          0x02D
    #define RANGE_CHECK_ECE_ENABLE_MASK      0x01
    #define RANGE_CHECK_RANGE_ENABLE_MASK    0x02
    #define RANGE_CHECK_SNR_ENABLE           0x10

#define SYSRANGE_VHV_RECALIBRATE              0x02E
#define SYSRANGE_VHV_REPEAT_RATE              0x031

/**
 * @def SYSALS_START
 * @brief Start/stop and set operating als mode
 *
 * same bit definition as range \a #SYSRANGE_START \n
 */
#define SYSALS_START                          0x038

/** ALS low Threshold high */
#define SYSALS_THRESH_HIGH                    0x03A
/** ALS low Threshold low */
#define SYSALS_THRESH_LOW                     0x03C
/** ALS intermeasurement period */
#define SYSALS_INTERMEASUREMENT_PERIOD        0x03E
/**
 * @warning or value with 0x40 when writing to these register*/
#define SYSALS_ANALOGUE_GAIN                  0x03F
/** ALS integration period */
#define SYSALS_INTEGRATION_PERIOD             0x040

/**
 * @brief Result range status
 *
 *  Hold the various range interrupt flags and error Specific error codes
 */
#define RESULT_RANGE_STATUS                   0x04D
    /** Device ready for new command bit 0*/
    #define RANGE_DEVICE_READY_MASK       0x01
    /** mask for error status covers bits [7:4]  in #RESULT_RANGE_STATUS @a ::RangeError_u */
    #define RANGE_ERROR_CODE_MASK         0xF0 /* */
    /** range error bit position in #RESULT_RANGE_STATUS */
    #define RANGE_ERROR_CODE_SHIFT        4

/**
 * @def RESULT_ALS_STATUS
 * @brief Result  als status \n
 *  Hold the various als interrupt flags and Specific error codes
 */
#define RESULT_ALS_STATUS                     0x4E
    /** Device ready for new command bit 0*/
   #define ALS_DEVICE_READY_MASK       0x01

/**
 * @def RESULT_ALS_VAL
 * @brief 16 Bit ALS count output value.
 *
 * Lux value depends on Gain and integration settings and calibrated lux/count setting
 * \a VL6180x_AlsGetLux() \a VL6180x_AlsGetMeasurement()
 */
#define RESULT_ALS_VAL                        0x50

/**
 * @def FW_ALS_RESULT_SCALER
 * @brief Als scaler register  Bits [3:0] analogue gain 1 to 16x
 * these register content is cached by API in \a VL6180xDevData_t::AlsScaler
 * for lux computation acceleration
 */
#define FW_ALS_RESULT_SCALER                  0x120


/**
 * these union can be use as a generic bit field type for map #RESULT_INTERRUPT_STATUS_GPIO register
 * @ingroup device_regdef
 */
typedef union IntrStatus_u {
	uint8_t val;           /*!< raw 8 bit register value*/
	struct  {
		unsigned Range:3; /*!< Range status one of :\n  \a #RES_INT_STAT_GPIO_LOW_LEVEL_THRESHOLD  \n \a #RES_INT_STAT_GPIO_HIGH_LEVEL_THRESHOLD  \n \a #RES_INT_STAT_GPIO_OUT_OF_WINDOW \n \a #RES_INT_STAT_GPIO_NEW_SAMPLE_READY */
		unsigned Als:3; /*!< Als status one of: \n \a #RES_INT_STAT_GPIO_LOW_LEVEL_THRESHOLD  \n \a #RES_INT_STAT_GPIO_HIGH_LEVEL_THRESHOLD  \n \a #RES_INT_STAT_GPIO_OUT_OF_WINDOW \n \a #RES_INT_STAT_GPIO_NEW_SAMPLE_READY  */
		unsigned Error:2; /*!<  Error status of: \n \a #RES_INT_ERROR_LASER_SAFETY  \n \a #RES_INT_ERROR_PLL */
	} status;                 /*!< interrupt status as bit field */
} IntrStatus_t;

/**
 * @def RESULT_INTERRUPT_STATUS_GPIO
 * @brief System interrupt status report selected interrupt for als and ranging
 *
 * These register can be polled even if no gpio pins is active\n
 * What reported is selected by \a  #SYSTEM_INTERRUPT_CONFIG_GPIO \n
 * Range mask with \a #RES_INT_RANGE_MASK and shit by \a #RES_INT_RANGE_SHIFT
 * Als   mask with \a #RES_INT_ALS_MASK and shit by \a #RES_INT_ALS_SHIFT
 * Result value express condition (or combination?)
 * \a #RES_INT_STAT_GPIO_LOW_LEVEL_THRESHOLD \n
 * \a #RES_INT_STAT_GPIO_HIGH_LEVEL_THRESHOLD \n
 * \a #RES_INT_STAT_GPIO_OUT_OF_WINDOW \n
 * \a #RES_INT_STAT_GPIO_NEW_SAMPLE_READY
 *
 * @ingroup device_regdef
 */
#define RESULT_INTERRUPT_STATUS_GPIO          0x4F
    /** ranging interrupt 1st bit position in #RESULT_INTERRUPT_STATUS_GPIO */
    #define RES_INT_RANGE_SHIFT  0
    /** ALS interrupt 1st bit position in #RESULT_INTERRUPT_STATUS_GPIO */
    #define RES_INT_ALS_SHIFT    3
    /** interrupt bit position in #RESULT_INTERRUPT_STATUS_GPIO */
    #define RES_INT_ERROR_SHIFT  6
    /** Ranging interrupt mask in #RESULT_INTERRUPT_STATUS_GPIO (prior to shift)  \sa IntrStatus_t */
    #define RES_INT_RANGE_MASK (0x7<<RES_INT_RANGE_SHIFT)
    /** als interrupt mask in #RESULT_INTERRUPT_STATUS_GPIO (prior to shift)  \sa IntrStatus_t */
    #define RES_INT_ALS_MASK   (0x7<<RES_INT_ALS_SHIFT)

    /** low threshold condition in #RESULT_INTERRUPT_STATUS_GPIO for */
    #define RES_INT_STAT_GPIO_LOW_LEVEL_THRESHOLD  0x01
    /** high threshold condition in #RESULT_INTERRUPT_STATUS_GPIO for ALs or Rage*/
    #define RES_INT_STAT_GPIO_HIGH_LEVEL_THRESHOLD 0x02
    /** out of window condition in #RESULT_INTERRUPT_STATUS_GPIO */
    #define RES_INT_STAT_GPIO_OUT_OF_WINDOW        0x03
    /** new sample ready in #RESULT_INTERRUPT_STATUS_GPIO */
    #define RES_INT_STAT_GPIO_NEW_SAMPLE_READY     0x04
    /** error  in #RESULT_INTERRUPT_STATUS_GPIO */
    #define RES_INT_ERROR_MASK (0x3<<RES_INT_ERROR_SHIFT)
	/** laser safety error on #RES_INT_ERROR_MASK of #RESULT_INTERRUPT_STATUS_GPIO */
	#define RES_INT_ERROR_LASER_SAFETY  1
	/** pll 1 or 2 error on #RES_INT_ERROR_MASK of #RESULT_INTERRUPT_STATUS_GPIO*/
	#define RES_INT_ERROR_PLL           2

/**
 * Final range result value presented to the user for use. Unit is in mm.
 */
#define RESULT_RANGE_VAL                        0x062

/**
 * Raw Range result value with offset applied (no cross talk compensation applied). Unit is in mm.
 */
#define RESULT_RANGE_RAW                        0x064

/**
 * @brief Sensor count rate of signal returns correlated to IR emitter.
 *
 * Computed from RETURN_SIGNAL_COUNT / RETURN_CONV_TIME. Mcps 9.7 format
 */
#define RESULT_RANGE_SIGNAL_RATE                0x066

/**
 * @brief Return signal count
 *
 *  Sensor count output value attributed to signal correlated to IR emitter on the Return array.
 */
#define RESULT_RANGE_RETURN_SIGNAL_COUNT        0x06C

/**
 * @brief Reference signal count
 *
 * sensor count output value attributed to signal correlated to IR emitter on the Reference array.
 */
#define RESULT_RANGE_REFERENCE_SIGNAL_COUNT     0x070

/**
 * @brief Return ambient count
 *
 * sensor count output value attributed to uncorrelated ambient signal on the Return array.
 * Must be multiplied by 6 if used to calculate the ambient to signal threshold
 */
#define RESULT_RANGE_RETURN_AMB_COUNT           0x074

/**
 * @brief   Reference ambient count
 *
 * Sensor count output value attributed to uncorrelated ambient signal on the Reference array.
 */
#define RESULT_RANGE_REFERENCE_AMB_COUNT        0x078

/**
 * sensor count output value attributed to signal on the Return array.
 */
#define RESULT_RANGE_RETURN_CONV_TIME           0x07C

/**
 * sensor count output value attributed to signal on the Reference array.
 */
#define RESULT_RANGE_REFERENCE_CONV_TIME        0x080


/**
 * @def RANGE_SCALER
 * @brief RANGE scaling register
 *
 * Never should  user write directly onto that register directly \a VL6180x_UpscaleSetScaling()
 */
#define RANGE_SCALER                            0x096

/**
 * @def READOUT_AVERAGING_SAMPLE_PERIOD
 * @brief Readout averaging sample period register
 *
 *
 * The internal readout averaging sample period can be adjusted from 0 to 255.
 * Increasing the sampling period decreases noise but also reduces the effective
 * max convergence time and increases power consumption
 * Each unit sample period corresponds to around 64.5 Î¼s additional processing time.
 * The recommended setting is 48 which equates to around 4.3 ms.
 *
 * see datasheet for more detail
 */
#define READOUT_AVERAGING_SAMPLE_PERIOD     0x10A

/**
 * @def I2C_SLAVE_DEVICE_ADDRESS
 * User programmable I2C address (7-bit). Device address can be re-designated after power-up.
 * @warning What programmed in the register 7-0 are bit 8-1 of i2c address on bus (bit 0 is rd/wr)
 * so what prohamd is commonly whar ergfer as adrerss /2
 * @sa VL6180x_SetI2CAddress()
 */
#define I2C_SLAVE_DEVICE_ADDRESS               0x212

#endif
