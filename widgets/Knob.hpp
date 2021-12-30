/*
 * Copyright (C) 2021 Rob van den Berg <rghvdberg at gmail dot com>
 * SPDX-License-Identifier: ISC
*/

#pragma once

#include "NanoKnob.hpp"

START_NAMESPACE_DGL

class Knob : public NanoKnob
{
public:
    explicit Knob(Widget* parent, KnobEventHandler::Callback* cb);

protected:
    void onNanoDisplay() override;

private:

    DISTRHO_LEAK_DETECTOR(Knob)
};

END_NAMESPACE_DGL
