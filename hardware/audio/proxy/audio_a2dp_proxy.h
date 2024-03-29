/*
 * Copyright (C) 2017 The Android Open Source Project
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

#ifndef AUDIO_A2DP_PROXY_H
#define AUDIO_A2DP_PROXY_H

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
**  Constants & Macros
******************************************************************************/

#if 0
enum {
    ENC_CODEC_TYPE_SBC  = 520093696u, // 0x1F000000UL
    ENC_CODEC_TYPE_APTX = 536870912u, // 0x20000000UL
};
#endif

/* Encoder Format & Channel Definition */
#define ENC_MEDIA_FMT_APTX      0x000131ff
#define ENC_MEDIA_FMT_APTX_HD   0x00013200
#define ENC_MEDIA_FMT_SBC       0x00010BF2
#define ENC_MEDIA_FMT_SSC       0x00010BF3
#define ENC_MEDIA_FMT_AAC       0x00010DA6

#define PCM_CHANNEL_L           1
#define PCM_CHANNEL_R           2
#define PCM_CHANNEL_C           3

#define A2DP_CAL_LATENCY_VAL    150   // calibration value for bt-a2dp sync

/* These Configurations from A2DP IPC Library */
typedef struct {
    uint32_t subband;       /* 4, 8 */
    uint32_t blk_len;       /* 4, 8, 12, 16 */
    uint32_t bitrate;       /* 320kbps to 512kbps */
    /* Modified by samsung convgergence -- BEGIN */
    uint32_t frame_len;
    /* Modified by samsung convgergence -- END */
    uint16_t sampling_rate; /*44.1khz,48khz*/
    uint16_t peer_mtu;
    uint8_t  channels;      /*0(Mono),1(Dual_mono),2(Stereo),3(JS)*/
    uint8_t  alloc;         /*0(Loudness),1(SNR)*/
    uint8_t  min_bitpool;   /* 2 */
    uint8_t  max_bitpool;   /*53(44.1khz),51 (48khz) */
} audio_sbc_encoder_config;

typedef struct {
    uint32_t bitrate;
    uint16_t sampling_rate;
    uint16_t peer_mtu;
    uint8_t  channels;
} audio_aptx_encoder_config;

typedef enum {
    AUDIO_FORMAT_SSC = 637534208u, //0x26000000UL
}codec_t;

typedef struct {
    uint32_t bitrate;
    uint16_t sampling_rate;
    uint16_t peer_mtu;
    uint8_t  channels;
} audio_ssc_encoder_config;

typedef struct {
    uint32_t bitrate;
    uint16_t sampling_rate;
    uint16_t peer_mtu;
    uint8_t  channels;
} audio_aac_encoder_config;

/* These Configurations for Real A2DP Encoder */
struct sbc_enc_cfg_t {
    uint32_t      enc_format;
    uint32_t      num_subbands;
    uint32_t      blk_len;
    uint32_t      channel_mode;
    uint32_t      alloc_method;
    uint32_t      bit_rate;
    uint32_t      sample_rate;
    uint32_t      peer_mtu;
    /* Modified by samsung convgergence -- BEGIN */
    uint32_t      frame_len;
    /* Modified by samsung convgergence -- END */
} __packed;

struct aptx_enc_cfg_t {
    uint32_t      enc_format;
    uint32_t      sample_rate;
    uint32_t      num_channels;
    uint32_t      reserved;
    uint32_t      peer_mtu;
    uint32_t      channel_mapping[2];
} __packed;

struct ssc_enc_cfg_t {
    uint32_t      enc_format;
    uint32_t      sample_rate;
    uint32_t      num_channels;
    uint32_t      bitrate;
    uint32_t      peer_mtu;
    uint32_t      channel_mapping[2];
} __packed;

struct aac_enc_cfg_t {
    uint32_t      enc_format;
    uint32_t      sample_rate;
    uint32_t      num_channels;
    uint32_t      bitrate;
    uint32_t      peer_mtu;
    uint32_t      channel_mapping[2];
} __packed;


/*****************************************************************************
**  Interface in audio_a2dp_proxy
******************************************************************************/
void proxy_a2dp_set_mixer(uint32_t bit_rate, uint32_t peer_mtu);
int proxy_a2dp_get_config(uint32_t *, void *);

int proxy_a2dp_start(void);
int proxy_a2dp_stop(void);
int proxy_a2dp_suspend(bool);
bool proxy_a2dp_is_suspended(void); /* added by samsung audiocore */

int proxy_a2dp_open(void);
int proxy_a2dp_close(void);

int proxy_a2dp_init(void);
int proxy_a2dp_deinit(void);

/*****************************************************************************
**  Interface in audio_proxy
******************************************************************************/
void proxy_set_mixer_value_array(void *proxy, const char *name, const void *value, int count);

#ifdef __cplusplus
}
#endif

#endif /* AUDIO_A2DP_PROXY_H */
