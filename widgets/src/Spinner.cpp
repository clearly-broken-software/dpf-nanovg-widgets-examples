/*
 * Copyright (C) 2021 Rob van den Berg <rghvdberg at gmail dot com>
 * SPDX-License-Identifier: ISC
*/

#include "Spinner.hpp"

START_NAMESPACE_DGL

Spinner::Spinner(Widget *const parent, SpinnerEventHandler::Callback *const cb)
    : NanoSpinner(parent, cb)
{
}

void Spinner::onNanoDisplay()
{
    const uint w = getWidth();
    const uint h = getHeight();
    const float margin = 1.0f;

    // Background
    beginPath();
    fillColor(105,105,105);
    strokeColor(248,248,255);
    rect(margin, margin, w - 2 * margin, h - 2 * margin);
    fill();
    stroke();
    closePath();

    // incArea
    const Rectangle<double> incArea = getIncrementArea();
    beginPath();
    fillColor(205, 92, 92);
    rect(incArea.getX(), incArea.getY(), incArea.getWidth(), incArea.getHeight());
    fill();
    closePath();

    // deccArea
    const Rectangle<double> decArea = getDecrementArea();
    beginPath();
    fillColor(104, 205, 92); 
    rect(decArea.getX(), decArea.getY(), decArea.getWidth(), decArea.getHeight());
    fill();
    closePath();
}


END_NAMESPACE_DGL
