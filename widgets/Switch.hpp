/*
 * Copyright (C) 2021 Rob van den Berg <rghvdberg at gmail dot com>
 * SPDX-License-Identifier: ISC
*/

#pragma once

#include "NanoSwitch.hpp"

START_NAMESPACE_DGL

class Switch : public NanoSwitch
{
public:
    explicit Switch(Widget *parent, SwitchEventHandler::Callback *cb);

protected:
    void onNanoDisplay() override;


private:
    DISTRHO_LEAK_DETECTOR(Switch)
};

END_NAMESPACE_DGL

