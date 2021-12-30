/*
 * Copyright (C) 2021 Rob van den Berg <rghvdberg at gmail dot com>
 * SPDX-License-Identifier: ISC
*/

#include "Button.hpp"

START_NAMESPACE_DGL

Button::Button(Widget *const parent, ButtonEventHandler::Callback *const cb)
    : NanoButton(parent, cb)
{
    loadSharedResources();
    ButtonEventHandler::setCallback(cb);
}


void Button::onNanoDisplay()
{
    const uint w = getWidth();
    const uint h = getHeight();
    const float margin = 1.0f;

    // Background
    beginPath();
    fillColor(105,105,150);
    strokeColor(248,248,255);
    rect(margin, margin, w - 2 * margin, h - 2 * margin);
    fill();
    stroke();
    closePath();

    // Label
    beginPath();
    fontSize(14);
    fillColor(248,248,255);
    Rectangle<float> bounds;
    // get text width and height
    textBounds(0, 0, "BUTTON", NULL, bounds);

    // get center
    float tx = w / 2.0f;
    float ty = h / 2.0f;

    textAlign(ALIGN_CENTER | ALIGN_MIDDLE);
    fillColor(255, 255, 255, 255);
    text(tx, ty, "BUTTON", NULL);
    closePath();
}

END_NAMESPACE_DGL
