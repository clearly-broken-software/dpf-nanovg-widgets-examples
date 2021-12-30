/*
 * Copyright (C) 2021 Rob van den Berg <rghvdberg at gmail dot com>
 * SPDX-License-Identifier: ISC
*/

#pragma once

#include "NanoSlider.hpp"

START_NAMESPACE_DGL

class Slider : public NanoSlider
{
public:
    explicit Slider(Widget* parent, SliderEventHandler::Callback* cb);

protected:
    void onNanoDisplay() override;

private:

    DISTRHO_LEAK_DETECTOR(Slider)
};

END_NAMESPACE_DGL

