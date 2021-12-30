/*
 * Copyright (C) 2021 Rob van den Berg <rghvdberg at gmail dot com>
 * SPDX-License-Identifier: ISC
*/

#pragma once

#include "NanoButton.hpp"
#include <string>

START_NAMESPACE_DGL

class Button : public NanoButton
             {
public:
    explicit Button(Widget* parent, ButtonEventHandler::Callback* cb);
protected:
    void onNanoDisplay() override;

private:
    DISTRHO_LEAK_DETECTOR(Button)
};

END_NAMESPACE_DGL
