/*!
    \file    custom_hid_core.h
    \brief   definitions for HID core

    \version 2025-02-10, V2.2.0, firmware for GD32L23x, add support for GD32L235
*/

/*
    Copyright (c) 2025, GigaDevice Semiconductor Inc.

    Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors
       may be used to endorse or promote products derived from this software without
       specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
OF SUCH DAMAGE.
*/

#ifndef CUSTOM_HID_CORE_H
#define CUSTOM_HID_CORE_H

#include "usbd_enum.h"
#include "usb_hid.h"

#define DESC_LEN_REPORT             96U                     /*!< report descriptor length */
#define DESC_LEN_CONFIG             41U                     /*!< configuration descriptor length */

#define MAX_PERIPH_NUM              4U                      /*!< maximum peripheral number */

typedef struct {
    __ALIGNED(2) uint8_t data[2];                           /*!< custom HID data packet buff */

    __ALIGNED(2) uint8_t idlestate;                         /*!< idle state */
    __ALIGNED(2) uint8_t protocol;                          /*!< HID protocol */

    uint8_t reportID;                                       /*!< custom HID report id */
} custom_hid_handler;

typedef struct {
    void (*periph_config[MAX_PERIPH_NUM])(void);
} hid_fop_handler;

extern usb_desc custom_hid_desc;
extern usb_class custom_hid_class;

/* function declarations */
/* register HID interface operation functions */
uint8_t custom_hid_itfop_register(usb_dev *udev, hid_fop_handler *hid_fop);
/* send custom HID report */
uint8_t custom_hid_report_send(usb_dev *udev, uint8_t *report, uint16_t len);

#endif /* CUSTOM_HID_CORE_H */
