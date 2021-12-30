/*
 * Copyright (C) 2021 Rob van den Berg <rghvdberg at gmail dot com>
 * SPDX-License-Identifier: ISC
*/

#pragma once

#include "NanoSpinner.hpp"

START_NAMESPACE_DGL

class Spinner : public NanoSpinner
{
public:
    explicit Spinner(Widget *parent, SpinnerEventHandler::Callback *cb);

protected:
    void onNanoDisplay() override;
private:
 
    DISTRHO_LEAK_DETECTOR(Spinner)
};

END_NAMESPACE_DGL
