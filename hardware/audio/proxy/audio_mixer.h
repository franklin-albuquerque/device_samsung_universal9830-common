/*
 * Copyright (C) 2014 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __EXYNOS_AUDIOPROXY_MIXER_H__
#define __EXYNOS_AUDIOPROXY_MIXER_H__

#include <audio_route/audio_route.h>

/* Mixer Card Definition */
#define MIXER_CARD0     0


#define MAX_PATH_NAME_LEN 50
#define MAX_GAIN_PATH_NAME_LEN 55 //"gain-" + path_name size

/* Mixer Controls for ERAP Handling */
#define MAX_MIXER_NAME_LEN 50

// Mixer Control for BT A2DP
#define ABOX_A2DP_OFFLOAD_SET_PARAMS_NAME   "ABOX A2DP A2DP PARAM"
/* Modified by samsung convgergence -- BEGIN */
#define ABOX_A2DP_OFFLOAD_SET_PARAMS_COUNT  9
/* Modified by samsung convgergence -- END */

/* modified by samsung convgergence */
// Mixer control for BT A2DP offload Suspend (MCD Specific)
#define MIXER_CTL_ABOX_A2DP_SUSPEND_PARAMS     "ABOX A2DP SUSPEND PARAM"
#define MIXER_CTL_ABOX_A2DP_SUSPEND_PARAMS_CNT 1

// Mixer Control for set USB Mode
#define ABOX_USBMODE_CONTROL_NAME "ABOX ERAP info USB On"

// Mixer Control for set MUTE Control
#define ABOX_MUTE_CONTROL_NAME "ABOX ERAP info Mute Primary"
#define ABOX_MUTE_CNT_FOR_PATH_CHANGE 15

// Mixer Control for set A-Box Early WakeUp Control
#define ABOX_TICKLE_CONTROL_NAME "ABOX Tickle"
#define ABOX_TICKLE_ON      1

/**
 ** Sampling Rate, channels & format Modifier Configuration for USB playback
 **/
// SIFS0 config controls
#define ABOX_SAMPLE_RATE_MIXER_NAME     "ABOX SIFS0 Rate"
#define ABOX_CHANNELS_MIXER_NAME        "ABOX SIFS0 Channel"
#define ABOX_BIT_WIDTH_MIXER_NAME       "ABOX SIFS0 Width"
// WDMA3 config controls
#define ABOX_SAMPLE_RATE_WDMA3_NAME     "ABOX WDMA3 Rate"
#define ABOX_CHANNELS_WDMA3_NAME        "ABOX WDMA3 Channel"
#define ABOX_BIT_WIDTH_WDMA3_NAME       "ABOX WDMA3 Width"
#define ABOX_PERIOD_SIZE_WDMA3_NAME     "ABOX WDMA3 Period"

typedef enum {
    USBMODE        = 0,
    MUTE_CONTROL,
    TICKLE_CONTROL,
} erap_trigger;


// Mixer Control for set Android Audio Mode
#define ABOX_AUDIOMODE_CONTROL_NAME "ABOX Audio Mode"

#define SPK_AMPL_POWER_NAME "ABOX Spk AmpL Power"

// Compress Offload Volume
#define OFFLOAD_VOLUME_CONTROL_NAME "ABOX ComprTx0 Volume"
#define COMPRESS_PLAYBACK_VOLUME_MAX   8192

// Compress Offload Upscaling
#define OFFLOAD_UPSCALE_CONTROL_NAME "ABOX ComprTx0 Format"

//AEC_Control
#define ABOX_DNN_CONTROL_NAME "ABOX DNN PROCESS" // 1 : off / 0 : on
#define ABOX_DVTX_CONTROL_NAME "ABOX DVTx PROCESS"
#define MIXER_CTL_ABOX_NREC_CONTROL_PARAMS_CNT 1

// Call volume
#define CALL_VOLUME_CONTROL_NAME "ABOX Speech Volume"
#define CALL_PLAYBACK_VOLUME_MAX   15

#define CALL_RX_MUTE_CONTROL_NAME "ABOX Speech Rx Mute"
#define CALL_TX_MUTE_CONTROL_NAME "ABOX DVTx Tx Mute"

typedef enum {
    UPSCALE_NONE        = 0,
    UPSCALE_48K_16B,
    UPSCALE_48K_24B,
    UPSCALE_192K_24B,
    UPSCALE_384K_24B,
} upscale_factor;

// Mixer control for UAIF configuration
#define MIXER_CTL_ABOX_UAIF0_SWITCH      "ABOX UAIF0 Switch"
#define MIXER_CTL_ABOX_UAIF0_SAMPLERATE  "ABOX UAIF0 Rate"
#define MIXER_CTL_ABOX_UAIF0_WIDTH       "ABOX UAIF0 Width"
#define MIXER_CTL_ABOX_UAIF0_CHANNEL     "ABOX UAIF0 Channel"
#define MIXER_CTL_ABOX_UAIF1_SWITCH      "ABOX UAIF1 Switch"
#define MIXER_CTL_ABOX_UAIF1_SAMPLERATE  "ABOX UAIF1 Rate"
#define MIXER_CTL_ABOX_UAIF1_WIDTH       "ABOX UAIF1 Width"
#define MIXER_CTL_ABOX_UAIF1_CHANNEL     "ABOX UAIF1 Channel"
#define MIXER_CTL_ABOX_UAIF2_SWITCH      "ABOX UAIF2 Switch"
#define MIXER_CTL_ABOX_UAIF2_SAMPLERATE  "ABOX UAIF2 Rate"
#define MIXER_CTL_ABOX_UAIF2_WIDTH       "ABOX UAIF2 Width"
#define MIXER_CTL_ABOX_UAIF2_CHANNEL     "ABOX UAIF2 Channel"
#define MIXER_CTL_ABOX_UAIF3_SWITCH      "ABOX UAIF3 Switch"
#define MIXER_CTL_ABOX_UAIF3_SAMPLERATE  "ABOX UAIF3 Rate"
#define MIXER_CTL_ABOX_UAIF3_WIDTH       "ABOX UAIF3 Width"
#define MIXER_CTL_ABOX_UAIF3_CHANNEL     "ABOX UAIF3 Channel"

// Mixer control for SIFS configuration
#define MIXER_CTL_ABOX_SIFS0_SWITCH      "ABOX SIFS0 OUT Switch"
#define MIXER_CTL_ABOX_SIFS0_SAMPLERATE  "ABOX SIFS0 Rate"
#define MIXER_CTL_ABOX_SIFS0_WIDTH       "ABOX SIFS0 Width"
#define MIXER_CTL_ABOX_SIFS0_CHANNEL     "ABOX SIFS0 Channel"

#define MIXER_ON                         1
#define MIXER_OFF                        0

// USB Clock Source inforamtion mixer control
#define MIXER_CTL_ABOX_USB_CLOCKSOURCE   "ABOX PCM ext USB SCDS"

// Capture VirtualPCM DAI input source mixer control
#define MIXER_CTL_ABOX_CATPURE_VPCMDAI_INSRC    "ABOX VPCMIN_DAI0_A"

// MMAP Playback Volume
#define MIXER_CTL_ABOX_MMAP_OUT_VOLUME_CONTROL  "ABOX RDMA VOL FACTOR2"
#define MMAP_PLAYBACK_VOLUME_MAX   0xFFFFFF // Decimal value : 16777215

// Mixer control for BT A2DP offload (MCD Specific)
#define MIXER_CTL_ABOX_A2DP_DYN_PARAMS     "ABOX A2DP A2DP DYN PARAM"
#define MIXER_CTL_ABOX_A2DP_DYN_PARAMS_CNT 2

/**
 ** Call Parameter setting definitions & mixer controls
 **/
#define ABOX_CALL_PATH_PARAM "ABOX Call Path Param"

/**
 ** Display Port mixer controls to get support configurations information
 ** DP kernel driver return bit masked of supported configuration
 ** Supported Rates: 32000, 44100, 48000, 88200, 96000, 176400, 192000
 ** Supported Width: 16bit, 20bit, 24bit(padded)
 ** Supported channels: 1ch ~ 8ch
 ** e.g : if kernel controls returns 0x5 which means 44100 & 48000 are supported
 **/
#define MIXER_CTL_DP_SUP_SAMPLERATE      "DP AUDIO0 Rate"
#define MIXER_CTL_DP_SUP_WIDTH           "DP AUDIO0 Width"
#define MIXER_CTL_DP_SUP_CHANNEL         "DP AUDIO0 Channel"

/**
 ** A-Box firmware debug-level setting control and
 ** system property definition for checking current debug level information
 **/
#define MIXER_CTL_ABOX_DEBUG_LEVEL          "ABOX Debug Level Low"
#define DEBUG_LEVEL_SYSTEM_PROPERTY         "ro.vendor.boot.debug_level"

/* System debug level and corresponding A-Box firmware debug level defintions */
#define SYSTEM_DEBUG_LEVEL_HIGH_VALUE       "0x4948"      // system debug level High
#define SYSTEM_DEBUG_LEVEL_MID_VALUE        "0x494d"      // system debug level Medium
#define SYSTEM_DEBUG_LEVEL_LOW_VALUE        "0x4f4c"      // system debug level low

#define ABOX_DEBUG_LEVEL_HIGH_VALUE         0      // A-Box debug level High
#define ABOX_DEBUG_LEVEL_MID_VALUE          1      // A-Box debug level Medium
#define ABOX_DEBUG_LEVEL_LOW_VALUE          2      // A-Box debug level low

#endif  // __EXYNOS_AUDIOPROXY_MIXER_H__
