/*
 * Copyright (C) 2021 Rob van den Berg <rghvdberg at gmail dot com>
 * SPDX-License-Identifier: ISC
*/

#include "Knob.hpp"

Knob::Knob(Widget *const parent, KnobEventHandler::Callback *const cb)
    : NanoKnob(parent, cb)
{
}

void Knob::onNanoDisplay()
{
    const uint w = getWidth();
    const uint h = getHeight();
    const float margin = 1.0f;
    const float radius = (h - margin) / 2.0f;
    const float center_x = (w * .5f);
    const float center_y = radius + margin;
    const float val = getValue();
    const float gaugeWidth = 5.f;
    //Gauge (empty)
    beginPath();
    strokeWidth(gaugeWidth);
    strokeColor(105, 105, 150);
    arc(center_x, center_y, radius - gaugeWidth / 2, 0.75f * M_PI, 0.25f * M_PI, NanoVG::Winding::CW);
    stroke();
    closePath();
    //Gauge (value)
    beginPath();
    strokeWidth(gaugeWidth);

    strokeColor(248, 248, 255);

    {
        arc(center_x,
            center_y,
            radius - gaugeWidth / 2,
            0.75f * M_PI,
            (0.75f + 1.5f * val) * M_PI,
            NanoVG::Winding::CW);
    }
    stroke();
    closePath();
}