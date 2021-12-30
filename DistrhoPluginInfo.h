/*
 * DISTRHO Plugin Framework (DPF)
 * Copyright (C) 2012-2020 Filipe Coelho <falktx@falktx.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any purpose with
 * or without fee is hereby granted, provided that the above copyright notice and this
 * permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD
 * TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN
 * NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#pragma once

#define DISTRHO_PLUGIN_BRAND "Cleary Broken Software"
#define DISTRHO_PLUGIN_NAME "NanoVG Widgets Demo"
#define DISTRHO_PLUGIN_URI "urn:clearlybrokensoftware:dpfwidgetsdemo"

#define DISTRHO_PLUGIN_HAS_UI 1
#define DISTRHO_PLUGIN_IS_RT_SAFE 1
#define DISTRHO_PLUGIN_NUM_INPUTS 1
#define DISTRHO_PLUGIN_NUM_OUTPUTS 1
#define DISTRHO_UI_USE_NANOVG 1

enum Parameters
{
    kButton,
    kKnob,
    kSlider,
    kSpinner,
    kSwitch,
    kParameterCount
};
