/*
 * Copyright (C) 2021 Rob van den Berg <rghvdberg at gmail dot com>
 * SPDX-License-Identifier: ISC
*/

#include "Slider.hpp"

START_NAMESPACE_DGL

Slider::Slider(Widget *const parent, SliderEventHandler::Callback *const cb)
    : NanoSlider(parent, cb)
{
}

void Slider::onNanoDisplay()
{
    const uint w = getWidth();
    const uint h = getHeight();
    const float val = getValue();
    beginPath();
    fillColor(105,105,150);
    rect(0, 0, w, h);
    fill();
    closePath();
    beginPath();
    fillColor(248,248,255);
    if (isInverted())
    {
        rect(0, h - h * val, w, h);
    }
    else
    {
        rect(0, 0, w, h * val);
    }
    fill();
    closePath();
}

END_NAMESPACE_DGL
