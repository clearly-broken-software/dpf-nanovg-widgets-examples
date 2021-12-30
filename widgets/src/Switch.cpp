/*
 * Copyright (C) 2021 Rob van den Berg <rghvdberg at gmail dot com>
 * SPDX-License-Identifier: ISC
*/

#include "Switch.hpp"

START_NAMESPACE_DGL

Switch::Switch(Widget *const parent, SwitchEventHandler::Callback *const cb)
    : NanoSwitch(parent, cb)
{
}

void Switch::onNanoDisplay()
{
    const uint w = getWidth();
    const uint h = getHeight();

    beginPath();
    isDown() ? fillColor(205, 92, 92) : fillColor(104, 205, 92);
    rect(0, 0, w, h);
    fill();
    closePath();
}

END_NAMESPACE_DGL
