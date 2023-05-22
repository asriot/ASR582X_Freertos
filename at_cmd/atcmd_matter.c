/*
 * Copyright (c) 2022 ASR Microelectronics (Shanghai) Co., Ltd. All rights reserved.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifdef AT_USER_DEBUG

#include "lega_at_api.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef CFG_PLF_DUET
#include "duet_common.h"
#include "duet_flash.h"
#include "duet_flash_kv.h"
#else
#include "lega_common.h"
#endif
#include "lega_wlan_api.h"

#define CONFIG_ENABLE_ASR_FACTORY_TEST 0
/*
 ************************************************************
 *                    USER AT CMD START
 *
 ************************************************************
 */
#if CONFIG_ENABLE_ASR_FACTORY_TEST
static const uint8_t at_kDevelopmentDAC_Cert_FFF1_8001[491] = {
    0x30, 0x82, 0x01, 0xe7, 0x30, 0x82, 0x01, 0x8e, 0xa0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x08, 0x69, 0xcd, 0xf1, 0x0d, 0xe9, 0xe5,
    0x4e, 0xd1, 0x30, 0x0a, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x04, 0x03, 0x02, 0x30, 0x3d, 0x31, 0x25, 0x30, 0x23, 0x06,
    0x03, 0x55, 0x04, 0x03, 0x0c, 0x1c, 0x4d, 0x61, 0x74, 0x74, 0x65, 0x72, 0x20, 0x44, 0x65, 0x76, 0x20, 0x50, 0x41, 0x49, 0x20,
    0x30, 0x78, 0x46, 0x46, 0x46, 0x31, 0x20, 0x6e, 0x6f, 0x20, 0x50, 0x49, 0x44, 0x31, 0x14, 0x30, 0x12, 0x06, 0x0a, 0x2b, 0x06,
    0x01, 0x04, 0x01, 0x82, 0xa2, 0x7c, 0x02, 0x01, 0x0c, 0x04, 0x46, 0x46, 0x46, 0x31, 0x30, 0x20, 0x17, 0x0d, 0x32, 0x32, 0x30,
    0x32, 0x30, 0x35, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x5a, 0x18, 0x0f, 0x39, 0x39, 0x39, 0x39, 0x31, 0x32, 0x33, 0x31, 0x32,
    0x33, 0x35, 0x39, 0x35, 0x39, 0x5a, 0x30, 0x53, 0x31, 0x25, 0x30, 0x23, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0c, 0x1c, 0x4d, 0x61,
    0x74, 0x74, 0x65, 0x72, 0x20, 0x44, 0x65, 0x76, 0x20, 0x44, 0x41, 0x43, 0x20, 0x30, 0x78, 0x46, 0x46, 0x46, 0x31, 0x2f, 0x30,
    0x78, 0x38, 0x30, 0x30, 0x31, 0x31, 0x14, 0x30, 0x12, 0x06, 0x0a, 0x2b, 0x06, 0x01, 0x04, 0x01, 0x82, 0xa2, 0x7c, 0x02, 0x01,
    0x0c, 0x04, 0x46, 0x46, 0x46, 0x31, 0x31, 0x14, 0x30, 0x12, 0x06, 0x0a, 0x2b, 0x06, 0x01, 0x04, 0x01, 0x82, 0xa2, 0x7c, 0x02,
    0x02, 0x0c, 0x04, 0x38, 0x30, 0x30, 0x31, 0x30, 0x59, 0x30, 0x13, 0x06, 0x07, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x02, 0x01, 0x06,
    0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x03, 0x01, 0x07, 0x03, 0x42, 0x00, 0x04, 0x46, 0x3a, 0xc6, 0x93, 0x42, 0x91, 0x0a, 0x0e,
    0x55, 0x88, 0xfc, 0x6f, 0xf5, 0x6b, 0xb6, 0x3e, 0x62, 0xec, 0xce, 0xcb, 0x14, 0x8f, 0x7d, 0x4e, 0xb0, 0x3e, 0xe5, 0x52, 0x60,
    0x14, 0x15, 0x76, 0x7d, 0x16, 0xa5, 0xc6, 0x63, 0xf7, 0x93, 0xe4, 0x91, 0x23, 0x26, 0x0b, 0x82, 0x97, 0xa7, 0xcd, 0x7e, 0x7c,
    0xfc, 0x7b, 0x31, 0x6b, 0x39, 0xd9, 0x8e, 0x90, 0xd2, 0x93, 0x77, 0x73, 0x8e, 0x82, 0xa3, 0x60, 0x30, 0x5e, 0x30, 0x0c, 0x06,
    0x03, 0x55, 0x1d, 0x13, 0x01, 0x01, 0xff, 0x04, 0x02, 0x30, 0x00, 0x30, 0x0e, 0x06, 0x03, 0x55, 0x1d, 0x0f, 0x01, 0x01, 0xff,
    0x04, 0x04, 0x03, 0x02, 0x07, 0x80, 0x30, 0x1d, 0x06, 0x03, 0x55, 0x1d, 0x0e, 0x04, 0x16, 0x04, 0x14, 0x88, 0xdd, 0xe7, 0xb3,
    0x00, 0x38, 0x29, 0x32, 0xcf, 0xf7, 0x34, 0xc0, 0x46, 0x24, 0x81, 0x0f, 0x44, 0x16, 0x8a, 0x6f, 0x30, 0x1f, 0x06, 0x03, 0x55,
    0x1d, 0x23, 0x04, 0x18, 0x30, 0x16, 0x80, 0x14, 0x63, 0x54, 0x0e, 0x47, 0xf6, 0x4b, 0x1c, 0x38, 0xd1, 0x38, 0x84, 0xa4, 0x62,
    0xd1, 0x6c, 0x19, 0x5d, 0x8f, 0xfb, 0x3c, 0x30, 0x0a, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x04, 0x03, 0x02, 0x03, 0x47,
    0x00, 0x30, 0x44, 0x02, 0x20, 0x01, 0x27, 0xa2, 0x7b, 0x4b, 0x44, 0x61, 0x0e, 0xe2, 0xfc, 0xdc, 0x4d, 0x2b, 0x78, 0x85, 0x56,
    0x36, 0x60, 0xbc, 0x0f, 0x76, 0xf1, 0x72, 0x19, 0xed, 0x6a, 0x08, 0xdf, 0xb2, 0xb3, 0xc1, 0xcd, 0x02, 0x20, 0x6b, 0x59, 0xe0,
    0xaf, 0x45, 0xf3, 0xeb, 0x2a, 0x85, 0xb9, 0x19, 0xd3, 0x57, 0x31, 0x52, 0x8c, 0x60, 0x28, 0xc4, 0x15, 0x23, 0x95, 0x45, 0xe1,
    0x08, 0xe4, 0xe5, 0x4e, 0x70, 0x97, 0x13, 0x53,
};
static const uint8_t at_DevelopmentDAC_PublicKey_FFF1_8001[65] = {
    0x04, 0x46, 0x3a, 0xc6, 0x93, 0x42, 0x91, 0x0a, 0x0e, 0x55, 0x88, 0xfc, 0x6f, 0xf5, 0x6b, 0xb6, 0x3e,
    0x62, 0xec, 0xce, 0xcb, 0x14, 0x8f, 0x7d, 0x4e, 0xb0, 0x3e, 0xe5, 0x52, 0x60, 0x14, 0x15, 0x76, 0x7d,
    0x16, 0xa5, 0xc6, 0x63, 0xf7, 0x93, 0xe4, 0x91, 0x23, 0x26, 0x0b, 0x82, 0x97, 0xa7, 0xcd, 0x7e, 0x7c,
    0xfc, 0x7b, 0x31, 0x6b, 0x39, 0xd9, 0x8e, 0x90, 0xd2, 0x93, 0x77, 0x73, 0x8e, 0x82,
};
static const uint8_t at_kDevelopmentDAC_PrivateKey_FFF1_8001[32] = {
    0xaa, 0xb6, 0x00, 0xae, 0x8a, 0xe8, 0xaa, 0xb7, 0xd7, 0x36, 0x27, 0xc2, 0x17, 0xb7, 0xc2, 0x04,
    0x70, 0x9c, 0xa6, 0x94, 0x6a, 0xf5, 0xf2, 0xf7, 0x53, 0x08, 0x33, 0xa5, 0x2b, 0x44, 0xfb, 0xff,
};
//-> format_version = 1
//-> vendor_id = 0xFFF1
//-> product_id_array = [ 0x8000, 0x8001, 0x8002, 0x8003, 0x8004, 0x8005, 0x8006, 0x8007, 0x8008, 0x8009, 0x800A, 0x800B,
// 0x800C, 0x800D, 0x800E, 0x800F, 0x8010, 0x8011, 0x8012, 0x8013, 0x8014, 0x8015, 0x8016, 0x8017, 0x8018, 0x8019, 0x801A,
// 0x801B, 0x801C, 0x801D, 0x801E, 0x801F, 0x8020, 0x8021, 0x8022, 0x8023, 0x8024, 0x8025, 0x8026, 0x8027, 0x8028, 0x8029,
// 0x802A, 0x802B, 0x802C, 0x802D, 0x802E, 0x802F, 0x8030, 0x8031, 0x8032, 0x8033, 0x8034, 0x8035, 0x8036, 0x8037, 0x8038,
// 0x8039, 0x803A, 0x803B, 0x803C, 0x803D, 0x803E, 0x803F, 0x8040, 0x8041, 0x8042, 0x8043, 0x8044, 0x8045, 0x8046, 0x8047,
// 0x8048, 0x8049, 0x804A, 0x804B, 0x804C, 0x804D, 0x804E, 0x804F, 0x8050, 0x8051, 0x8052, 0x8053, 0x8054, 0x8055, 0x8056,
// 0x8057, 0x8058, 0x8059, 0x805A, 0x805B, 0x805C, 0x805D, 0x805E, 0x805F, 0x8060, 0x8061, 0x8062, 0x8063 ]
//-> device_type_id = 0x0016
//-> certificate_id = "ZIG20142ZB330003-24"
//-> security_level = 0
//-> security_information = 0
//-> version_number = 0x2694
//-> certification_type = 0
//-> dac_origin_vendor_id is not present
//-> dac_origin_product_id is not present
static const uint8_t at_CdForAllExamples[541] = {
    0x30, 0x82, 0x02, 0x19, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x07, 0x02, 0xa0, 0x82, 0x02, 0x0a, 0x30, 0x82,
    0x02, 0x06, 0x02, 0x01, 0x03, 0x31, 0x0d, 0x30, 0x0b, 0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01, 0x30,
    0x82, 0x01, 0x71, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x07, 0x01, 0xa0, 0x82, 0x01, 0x62, 0x04, 0x82, 0x01,
    0x5e, 0x15, 0x24, 0x00, 0x01, 0x25, 0x01, 0xf1, 0xff, 0x36, 0x02, 0x05, 0x00, 0x80, 0x05, 0x01, 0x80, 0x05, 0x02, 0x80, 0x05,
    0x03, 0x80, 0x05, 0x04, 0x80, 0x05, 0x05, 0x80, 0x05, 0x06, 0x80, 0x05, 0x07, 0x80, 0x05, 0x08, 0x80, 0x05, 0x09, 0x80, 0x05,
    0x0a, 0x80, 0x05, 0x0b, 0x80, 0x05, 0x0c, 0x80, 0x05, 0x0d, 0x80, 0x05, 0x0e, 0x80, 0x05, 0x0f, 0x80, 0x05, 0x10, 0x80, 0x05,
    0x11, 0x80, 0x05, 0x12, 0x80, 0x05, 0x13, 0x80, 0x05, 0x14, 0x80, 0x05, 0x15, 0x80, 0x05, 0x16, 0x80, 0x05, 0x17, 0x80, 0x05,
    0x18, 0x80, 0x05, 0x19, 0x80, 0x05, 0x1a, 0x80, 0x05, 0x1b, 0x80, 0x05, 0x1c, 0x80, 0x05, 0x1d, 0x80, 0x05, 0x1e, 0x80, 0x05,
    0x1f, 0x80, 0x05, 0x20, 0x80, 0x05, 0x21, 0x80, 0x05, 0x22, 0x80, 0x05, 0x23, 0x80, 0x05, 0x24, 0x80, 0x05, 0x25, 0x80, 0x05,
    0x26, 0x80, 0x05, 0x27, 0x80, 0x05, 0x28, 0x80, 0x05, 0x29, 0x80, 0x05, 0x2a, 0x80, 0x05, 0x2b, 0x80, 0x05, 0x2c, 0x80, 0x05,
    0x2d, 0x80, 0x05, 0x2e, 0x80, 0x05, 0x2f, 0x80, 0x05, 0x30, 0x80, 0x05, 0x31, 0x80, 0x05, 0x32, 0x80, 0x05, 0x33, 0x80, 0x05,
    0x34, 0x80, 0x05, 0x35, 0x80, 0x05, 0x36, 0x80, 0x05, 0x37, 0x80, 0x05, 0x38, 0x80, 0x05, 0x39, 0x80, 0x05, 0x3a, 0x80, 0x05,
    0x3b, 0x80, 0x05, 0x3c, 0x80, 0x05, 0x3d, 0x80, 0x05, 0x3e, 0x80, 0x05, 0x3f, 0x80, 0x05, 0x40, 0x80, 0x05, 0x41, 0x80, 0x05,
    0x42, 0x80, 0x05, 0x43, 0x80, 0x05, 0x44, 0x80, 0x05, 0x45, 0x80, 0x05, 0x46, 0x80, 0x05, 0x47, 0x80, 0x05, 0x48, 0x80, 0x05,
    0x49, 0x80, 0x05, 0x4a, 0x80, 0x05, 0x4b, 0x80, 0x05, 0x4c, 0x80, 0x05, 0x4d, 0x80, 0x05, 0x4e, 0x80, 0x05, 0x4f, 0x80, 0x05,
    0x50, 0x80, 0x05, 0x51, 0x80, 0x05, 0x52, 0x80, 0x05, 0x53, 0x80, 0x05, 0x54, 0x80, 0x05, 0x55, 0x80, 0x05, 0x56, 0x80, 0x05,
    0x57, 0x80, 0x05, 0x58, 0x80, 0x05, 0x59, 0x80, 0x05, 0x5a, 0x80, 0x05, 0x5b, 0x80, 0x05, 0x5c, 0x80, 0x05, 0x5d, 0x80, 0x05,
    0x5e, 0x80, 0x05, 0x5f, 0x80, 0x05, 0x60, 0x80, 0x05, 0x61, 0x80, 0x05, 0x62, 0x80, 0x05, 0x63, 0x80, 0x18, 0x24, 0x03, 0x16,
    0x2c, 0x04, 0x13, 0x5a, 0x49, 0x47, 0x32, 0x30, 0x31, 0x34, 0x32, 0x5a, 0x42, 0x33, 0x33, 0x30, 0x30, 0x30, 0x33, 0x2d, 0x32,
    0x34, 0x24, 0x05, 0x00, 0x24, 0x06, 0x00, 0x25, 0x07, 0x94, 0x26, 0x24, 0x08, 0x00, 0x18, 0x31, 0x7d, 0x30, 0x7b, 0x02, 0x01,
    0x03, 0x80, 0x14, 0x62, 0xfa, 0x82, 0x33, 0x59, 0xac, 0xfa, 0xa9, 0x96, 0x3e, 0x1c, 0xfa, 0x14, 0x0a, 0xdd, 0xf5, 0x04, 0xf3,
    0x71, 0x60, 0x30, 0x0b, 0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01, 0x30, 0x0a, 0x06, 0x08, 0x2a, 0x86,
    0x48, 0xce, 0x3d, 0x04, 0x03, 0x02, 0x04, 0x47, 0x30, 0x45, 0x02, 0x20, 0x24, 0xe5, 0xd1, 0xf4, 0x7a, 0x7d, 0x7b, 0x0d, 0x20,
    0x6a, 0x26, 0xef, 0x69, 0x9b, 0x7c, 0x97, 0x57, 0xb7, 0x2d, 0x46, 0x90, 0x89, 0xde, 0x31, 0x92, 0xe6, 0x78, 0xc7, 0x45, 0xe7,
    0xf6, 0x0c, 0x02, 0x21, 0x00, 0xf8, 0xaa, 0x2f, 0xa7, 0x11, 0xfc, 0xb7, 0x9b, 0x97, 0xe3, 0x97, 0xce, 0xda, 0x66, 0x7b, 0xae,
    0x46, 0x4e, 0x2b, 0xd3, 0xff, 0xdf, 0xc3, 0xcc, 0xed, 0x7a, 0xa8, 0xca, 0x5f, 0x4c, 0x1a, 0x7c,
};

static const uint8_t at_DevelopmentPAI_Cert_FFF1[463] = {
    0x30, 0x82, 0x01, 0xcb, 0x30, 0x82, 0x01, 0x71, 0xa0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x08, 0x56, 0xad, 0x82, 0x22, 0xad, 0x94,
    0x5b, 0x64, 0x30, 0x0a, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x04, 0x03, 0x02, 0x30, 0x30, 0x31, 0x18, 0x30, 0x16, 0x06,
    0x03, 0x55, 0x04, 0x03, 0x0c, 0x0f, 0x4d, 0x61, 0x74, 0x74, 0x65, 0x72, 0x20, 0x54, 0x65, 0x73, 0x74, 0x20, 0x50, 0x41, 0x41,
    0x31, 0x14, 0x30, 0x12, 0x06, 0x0a, 0x2b, 0x06, 0x01, 0x04, 0x01, 0x82, 0xa2, 0x7c, 0x02, 0x01, 0x0c, 0x04, 0x46, 0x46, 0x46,
    0x31, 0x30, 0x20, 0x17, 0x0d, 0x32, 0x32, 0x30, 0x32, 0x30, 0x35, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x5a, 0x18, 0x0f, 0x39,
    0x39, 0x39, 0x39, 0x31, 0x32, 0x33, 0x31, 0x32, 0x33, 0x35, 0x39, 0x35, 0x39, 0x5a, 0x30, 0x3d, 0x31, 0x25, 0x30, 0x23, 0x06,
    0x03, 0x55, 0x04, 0x03, 0x0c, 0x1c, 0x4d, 0x61, 0x74, 0x74, 0x65, 0x72, 0x20, 0x44, 0x65, 0x76, 0x20, 0x50, 0x41, 0x49, 0x20,
    0x30, 0x78, 0x46, 0x46, 0x46, 0x31, 0x20, 0x6e, 0x6f, 0x20, 0x50, 0x49, 0x44, 0x31, 0x14, 0x30, 0x12, 0x06, 0x0a, 0x2b, 0x06,
    0x01, 0x04, 0x01, 0x82, 0xa2, 0x7c, 0x02, 0x01, 0x0c, 0x04, 0x46, 0x46, 0x46, 0x31, 0x30, 0x59, 0x30, 0x13, 0x06, 0x07, 0x2a,
    0x86, 0x48, 0xce, 0x3d, 0x02, 0x01, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x03, 0x01, 0x07, 0x03, 0x42, 0x00, 0x04, 0x41,
    0x9a, 0x93, 0x15, 0xc2, 0x17, 0x3e, 0x0c, 0x8c, 0x87, 0x6d, 0x03, 0xcc, 0xfc, 0x94, 0x48, 0x52, 0x64, 0x7f, 0x7f, 0xec, 0x5e,
    0x50, 0x82, 0xf4, 0x05, 0x99, 0x28, 0xec, 0xa8, 0x94, 0xc5, 0x94, 0x15, 0x13, 0x09, 0xac, 0x63, 0x1e, 0x4c, 0xb0, 0x33, 0x92,
    0xaf, 0x68, 0x4b, 0x0b, 0xaf, 0xb7, 0xe6, 0x5b, 0x3b, 0x81, 0x62, 0xc2, 0xf5, 0x2b, 0xf9, 0x31, 0xb8, 0xe7, 0x7a, 0xaa, 0x82,
    0xa3, 0x66, 0x30, 0x64, 0x30, 0x12, 0x06, 0x03, 0x55, 0x1d, 0x13, 0x01, 0x01, 0xff, 0x04, 0x08, 0x30, 0x06, 0x01, 0x01, 0xff,
    0x02, 0x01, 0x00, 0x30, 0x0e, 0x06, 0x03, 0x55, 0x1d, 0x0f, 0x01, 0x01, 0xff, 0x04, 0x04, 0x03, 0x02, 0x01, 0x06, 0x30, 0x1d,
    0x06, 0x03, 0x55, 0x1d, 0x0e, 0x04, 0x16, 0x04, 0x14, 0x63, 0x54, 0x0e, 0x47, 0xf6, 0x4b, 0x1c, 0x38, 0xd1, 0x38, 0x84, 0xa4,
    0x62, 0xd1, 0x6c, 0x19, 0x5d, 0x8f, 0xfb, 0x3c, 0x30, 0x1f, 0x06, 0x03, 0x55, 0x1d, 0x23, 0x04, 0x18, 0x30, 0x16, 0x80, 0x14,
    0x6a, 0xfd, 0x22, 0x77, 0x1f, 0x51, 0x1f, 0xec, 0xbf, 0x16, 0x41, 0x97, 0x67, 0x10, 0xdc, 0xdc, 0x31, 0xa1, 0x71, 0x7e, 0x30,
    0x0a, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x04, 0x03, 0x02, 0x03, 0x48, 0x00, 0x30, 0x45, 0x02, 0x21, 0x00, 0xb2, 0xef,
    0x27, 0xf4, 0x9a, 0xe9, 0xb5, 0x0f, 0xb9, 0x1e, 0xea, 0xc9, 0x4c, 0x4d, 0x0b, 0xdb, 0xb8, 0xd7, 0x92, 0x9c, 0x6c, 0xb8, 0x8f,
    0xac, 0xe5, 0x29, 0x36, 0x8d, 0x12, 0x05, 0x4c, 0x0c, 0x02, 0x20, 0x65, 0x5d, 0xc9, 0x2b, 0x86, 0xbd, 0x90, 0x98, 0x82, 0xa6,
    0xc6, 0x21, 0x77, 0xb8, 0x25, 0xd7, 0xd0, 0x5e, 0xdb, 0xe7, 0xc2, 0x2f, 0x9f, 0xea, 0x71, 0x22, 0x0e, 0x7e, 0xa7, 0x03, 0xf8,
    0x91,
};
const int pin_code        = 20202020;
const int discriminator   = 0xF11;
const int iteration_count = 1000;
// generated by spake2p tool
static const char salt[]     = "U1BBS0UyUCBLZXkgU2FsdCAx";
static const char verifier[] = "60JGuOQFjKgY63KrGhw48AsaU+8eVjCkGh99c1peMiQEVBDb/0ZYDgwFSMNQdgx/"
                               "OofZmYjxsPrDuQ4zu1ekZSqxbzXmKdI+78Fbf1wY43r9/0Vl1X9bkIHr3iaE3EbZVw==";

#if CONFIG_ENABLE_ASR_FACTORY_DEVICE_INFO_PROVIDER
const int vendor_id             = 0xFFF1;
static const char vendor_name[]  = "ASR";
const int product_id            = 0x8001;
static const char product_name[] = "asr582x";
#endif

#endif
void asr_matter_reset(int type);
void asr_matter_onoff(int cmd);
void asr_matter_sensors(bool enable, int temp, int humi, int pressure);
void ShutdownChip();
void asr_matter_ota(uint32_t timeout);

int at_matter_reset(int argc, char ** argv)
{
    if (argc < 2)
    {
        printf("para error\n");
        return CONFIG_OK;
    }
    if (strcmp(argv[1], "fab") == 0)
    {
        printf("resetting fabric info\n");
        asr_matter_reset(0);
    }
    else if (strcmp(argv[1], "factory") == 0)
    {
        printf("resetting factory info\n");
        asr_matter_reset(1);
    }
    else if (strcmp(argv[1], "wificommissioning") == 0)
    {
        printf("resetting to only wifi commissing\n");
        asr_matter_reset(2);
    }
    printf("reset matter done\r\n");
    return CONFIG_OK;
}

int at_matter(int argc, char ** argv)
{
    if (argc < 2)
    {
        printf("para error\n");
        return CONFIG_OK;
    }
    if (strcmp(argv[1], "stop") == 0)
    {
        ShutdownChip();
        printf("matter stop done\n");
    }
    else if (strcmp(argv[1], "start") == 0)
    {
        printf("not support\n");
    }
    return CONFIG_OK;
}

int at_matter_onoff(int argc, char ** argv)
{
    if (argc < 2)
    {
        printf("para error\n");
        return CONFIG_OK;
    }
    if (strcmp(argv[1], "on") == 0)
    {
        printf("button on\n");
        asr_matter_onoff(1);
    }
    else if (strcmp(argv[1], "off") == 0)
    {
        printf("button off\n");
        asr_matter_onoff(0);
    }
    return CONFIG_OK;
}

int at_matter_sensors(int argc, char ** argv)
{
    if (argc == 2 && strcmp(argv[1], "disable") == 0)
    {
        printf("sensor simulation disabled\n");
        asr_matter_sensors(false, 0, 0, 0);
    }
    else if (argc == 4)
    {
        int temp, humi, pressure;
        temp     = strtol(argv[1], NULL, 10);
        humi     = strtol(argv[2], NULL, 10);
        pressure = strtol(argv[3], NULL, 10);
        printf("simulate temp:%d humi:%d prssure:%d done\n", temp, humi, pressure);
        asr_matter_sensors(true, temp, humi, pressure);
    }
    else
    {
        printf("para error\n");
    }
    return CONFIG_OK;
}

#if CONFIG_ENABLE_ASR_FACTORY_TEST
#include "asr_factory_config.h"
#include "duet_flash.h"
#include "lega_rtos_api.h"
int at_set_facotry(int argc, char ** argv)
{
    printf("setting facotry data...\n");
    uint8_t * data_buf = lega_rtos_malloc(ASR_CONFIG_ALL_SIZE);
    memset(data_buf, 0x00, ASR_CONFIG_ALL_SIZE);
    asr_factory_config_buffer_write(ASR_ITERATION_COUNT_PARTITION, data_buf, &iteration_count, sizeof(iteration_count));
    asr_factory_config_buffer_write(ASR_SALT_PARTITION, data_buf, salt, sizeof(salt));
    asr_factory_config_buffer_write(ASR_VERIFIER_PARTITION, data_buf, verifier, sizeof(verifier));
    asr_factory_config_buffer_write(ASR_DISCRIMINATOR_PARTITION, data_buf, &discriminator, sizeof(discriminator));
    asr_factory_config_buffer_write(ASR_DAC_CERT_PARTITION, data_buf, at_kDevelopmentDAC_Cert_FFF1_8001,
                                    sizeof(at_kDevelopmentDAC_Cert_FFF1_8001));
    asr_factory_config_buffer_write(ASR_DAC_KEY_PARTITION, data_buf, at_kDevelopmentDAC_PrivateKey_FFF1_8001,
                                    sizeof(at_kDevelopmentDAC_PrivateKey_FFF1_8001));
    asr_factory_config_buffer_write(ASR_DAC_PUB_KEY_PARTITION, data_buf, at_DevelopmentDAC_PublicKey_FFF1_8001,
                                    sizeof(at_DevelopmentDAC_PublicKey_FFF1_8001));
    asr_factory_config_buffer_write(ASR_PAI_CERT_PARTITION, data_buf, at_DevelopmentPAI_Cert_FFF1,
                                    sizeof(at_DevelopmentPAI_Cert_FFF1));
    asr_factory_config_buffer_write(ASR_CERT_DCLRN_PARTITION, data_buf, at_CdForAllExamples, sizeof(at_CdForAllExamples));
#if CONFIG_ENABLE_ASR_FACTORY_DEVICE_INFO_PROVIDER
    asr_factory_config_buffer_write(ASR_VENDOR_NAME_PARTITION, data_buf, vendor_name, sizeof(vendor_name));
    asr_factory_config_buffer_write(ASR_VENDOR_ID_PARTITION, data_buf, &vendor_id, sizeof(vendor_id));
    asr_factory_config_buffer_write(ASR_PRODUCT_NAME_PARTITION, data_buf, product_name, sizeof(product_name));
    asr_factory_config_buffer_write(ASR_PRODUCT_ID_PARTITION, data_buf, &product_id, sizeof(product_id));
#endif
    asr_factory_config_write(data_buf, ASR_CONFIG_ALL_SIZE);
    lega_rtos_free(data_buf);
    return CONFIG_OK;
}
#endif

#if ENABLE_ASR_BRIDGE_SUBDEVICE_TEST
void Sync_SubDevice_test(void);
void Add_SubDevice_test(void);
void Remove_SubDevice_test(void);

int at_subdevice(int argc, char ** argv)
{
    if (argc < 2)
    {
        printf("para error\n");
        return CONFIG_OK;
    }
    if (strcmp(argv[1], "sync") == 0)
    {
        printf("sync all subdevices\n");
        Sync_SubDevice_test();
    }
    else if (strcmp(argv[1], "add") == 0)
    {
        printf("add light 2\n");
        Add_SubDevice_test();
    }
    else if (strcmp(argv[1], "remove") == 0)
    {
        printf("remove light 2\n");
        Remove_SubDevice_test();
    }
    return CONFIG_OK;
}
#endif

int at_matter_ota(int argc, char ** argv)
{
    if (argc < 2)
    {
        printf("para error\n");
        return CONFIG_OK;
    }
    uint32_t timeout = strtol(argv[1], NULL, 10);
    asr_matter_ota(timeout);
    return CONFIG_OK;
}

int at_matter_dis(int argc, char ** argv)
{
    if (argc < 2)
    {
        printf("para error\n");
        return CONFIG_OK;
    }
    uint32_t dis = strtol(argv[1], NULL, 10);

    if (dis < 0xFFF)
        duet_flash_kv_set("chip-factory;discriminator", &dis, 4, 1);

    return CONFIG_OK;
}
/*
 ************************************************************
 *                    USER AT CMD END
 *
 ************************************************************
 */

cmd_entry comm_at_reset_matter = {
    .name     = "matter_reset",
    .help     = "matter_reset fab/factory/wificommissioning",
    .function = at_matter_reset,
};
cmd_entry comm_at_matter = {
    .name     = "matter",
    .help     = "matter start/stop",
    .function = at_matter,
};
cmd_entry comm_at_onoff = {
    .name     = "matter_onoff",
    .help     = "matter_onoff on/off",
    .function = at_matter_onoff,
};
cmd_entry comm_at_simulate_sensors = {
    .name     = "matter_sensor_sim",
    .help     = "matter_sensor_sim disable/[temp humi pressure]",
    .function = at_matter_sensors,
};
#if CONFIG_ENABLE_ASR_FACTORY_TEST
cmd_entry comm_at_facotry = {
    .name     = "matter_set",
    .help     = "set matter facotry data",
    .function = at_set_facotry,
};
#endif
#if ENABLE_ASR_BRIDGE_SUBDEVICE_TEST
cmd_entry comm_at_subdevice = {
    .name     = "subdevice",
    .help     = "subdevice sync/add/remove",
    .function = at_subdevice,
};
#endif
cmd_entry comm_at_ota = {
    .name     = "matter_ota",
    .help     = "matter_ota [timeout]",
    .function = at_matter_ota,
};
cmd_entry comm_at_dis = {
    .name     = "matter_dis",
    .help     = "matter_dis [Discriminator]",
    .function = at_matter_dis,
};
void lega_at_matter_cmd_register(void)
{
    lega_at_cmd_register(&comm_at_matter);
    //lega_at_cmd_register(&comm_at_reset_matter);
    lega_at_cmd_register(&comm_at_onoff);
#if CONFIG_ENABLE_ASR_FACTORY_TEST
    lega_at_cmd_register(&comm_at_facotry);
#endif
#if ENABLE_ASR_BRIDGE_SUBDEVICE_TEST
    lega_at_cmd_register(&comm_at_subdevice);
#endif
    lega_at_cmd_register(&comm_at_simulate_sensors);
    lega_at_cmd_register(&comm_at_ota);
    lega_at_cmd_register(&comm_at_dis);
}
#endif
