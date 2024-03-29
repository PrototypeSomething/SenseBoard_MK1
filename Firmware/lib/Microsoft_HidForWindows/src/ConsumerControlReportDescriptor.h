// Copyright (c) Microsoft Corporation.  All rights reserved.
// Licensed under the MIT License.

#pragma once

// AUTO-GENERATED by WaratahCmd.exe (https://github.com/microsoft/hidtools)

// HID Usage Tables: 1.4.0
// Descriptor size: 257 (bytes)
// +----------+-------+-------------------+
// | ReportId | Kind  | ReportSizeInBytes |
// +----------+-------+-------------------+
// |        1 | Input |                 1 |
// +----------+-------+-------------------+
// |        2 | Input |                 1 |
// +----------+-------+-------------------+
// |        3 | Input |                 1 |
// +----------+-------+-------------------+
// |        4 | Input |                 1 |
// +----------+-------+-------------------+
// |        5 | Input |                 1 |
// +----------+-------+-------------------+
// |        6 | Input |                 1 |
// +----------+-------+-------------------+
// |        7 | Input |                 1 |
// +----------+-------+-------------------+
// |        8 | Input |                 1 |
// +----------+-------+-------------------+
// |        9 | Input |                 1 |
// +----------+-------+-------------------+
// |       10 | Input |                 1 |
// +----------+-------+-------------------+
// |       11 | Input |                 1 |
// +----------+-------+-------------------+
// |       12 | Input |                 1 |
// +----------+-------+-------------------+
// |       13 | Input |                 1 |
// +----------+-------+-------------------+
// |       14 | Input |                 1 |
// +----------+-------+-------------------+
// |       15 | Input |                 1 |
// +----------+-------+-------------------+
// |       16 | Input |                 1 |
// +----------+-------+-------------------+
// |       17 | Input |                 1 |
// +----------+-------+-------------------+
static const uint8_t ConsumerControlReportDescriptor[] PROGMEM = 
{
    0x05, 0x0C,          // UsagePage(Consumer[0x000C])
    0x09, 0x01,          // UsageId(Consumer Control[0x0001])
    0xA1, 0x01,          // Collection(Application)
    0x85, 0x01,          //     ReportId(1)
    0x09, 0xE9,          //     UsageId(Volume Increment[0x00E9])
    0x15, 0x00,          //     LogicalMinimum(0)
    0x25, 0x01,          //     LogicalMaximum(1)
    0x95, 0x01,          //     ReportCount(1)
    0x75, 0x01,          //     ReportSize(1)
    0x81, 0x02,          //     Input(Data, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x75, 0x07,          //     ReportSize(7)
    0x81, 0x03,          //     Input(Constant, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x85, 0x02,          //     ReportId(2)
    0x09, 0xEA,          //     UsageId(Volume Decrement[0x00EA])
    0x75, 0x01,          //     ReportSize(1)
    0x81, 0x02,          //     Input(Data, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x75, 0x07,          //     ReportSize(7)
    0x81, 0x03,          //     Input(Constant, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x85, 0x03,          //     ReportId(3)
    0x09, 0xE0,          //     UsageId(Volume[0x00E0])
    0x15, 0xFF,          //     LogicalMinimum(-1)
    0x25, 0x02,          //     LogicalMaximum(2)
    0x75, 0x03,          //     ReportSize(3)
    0x81, 0x02,          //     Input(Data, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x75, 0x05,          //     ReportSize(5)
    0x81, 0x03,          //     Input(Constant, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x85, 0x04,          //     ReportId(4)
    0x09, 0x6F,          //     UsageId(Display Brightness Increment[0x006F])
    0x15, 0x00,          //     LogicalMinimum(0)
    0x25, 0x01,          //     LogicalMaximum(1)
    0x75, 0x01,          //     ReportSize(1)
    0x81, 0x02,          //     Input(Data, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x75, 0x07,          //     ReportSize(7)
    0x81, 0x03,          //     Input(Constant, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x85, 0x05,          //     ReportId(5)
    0x09, 0x70,          //     UsageId(Display Brightness Decrement[0x0070])
    0x75, 0x01,          //     ReportSize(1)
    0x81, 0x02,          //     Input(Data, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x75, 0x07,          //     ReportSize(7)
    0x81, 0x03,          //     Input(Constant, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x85, 0x06,          //     ReportId(6)
    0x19, 0xD0,          //     UsageIdMin(Invoke Capture Interface[0x00D0])
    0x29, 0xD3,          //     UsageIdMax(Capture Game Screenshot[0x00D3])
    0x15, 0x01,          //     LogicalMinimum(1)
    0x25, 0x04,          //     LogicalMaximum(4)
    0x75, 0x03,          //     ReportSize(3)
    0x81, 0x00,          //     Input(Data, Array, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x75, 0x05,          //     ReportSize(5)
    0x81, 0x03,          //     Input(Constant, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x85, 0x07,          //     ReportId(7)
    0x0A, 0x8A, 0x01,    //     UsageId(AL Email Reader[0x018A])
    0x0A, 0x92, 0x01,    //     UsageId(AL Calculator[0x0192])
    0x0A, 0x94, 0x01,    //     UsageId(AL Local Machine Browser[0x0194])
    0x0A, 0x83, 0x01,    //     UsageId(AL Consumer Control Configuration[0x0183])
    0x75, 0x03,          //     ReportSize(3)
    0x81, 0x00,          //     Input(Data, Array, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x75, 0x05,          //     ReportSize(5)
    0x81, 0x03,          //     Input(Constant, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x85, 0x08,          //     ReportId(8)
    0x0A, 0x21, 0x02,    //     UsageId(AC Search[0x0221])
    0x0A, 0x23, 0x02,    //     UsageId(AC Home[0x0223])
    0x0A, 0x26, 0x02,    //     UsageId(AC Stop[0x0226])
    0x0A, 0x27, 0x02,    //     UsageId(AC Refresh[0x0227])
    0x75, 0x03,          //     ReportSize(3)
    0x81, 0x00,          //     Input(Data, Array, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x75, 0x05,          //     ReportSize(5)
    0x81, 0x03,          //     Input(Constant, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x85, 0x09,          //     ReportId(9)
    0x0A, 0x24, 0x02,    //     UsageId(AC Back[0x0224])
    0x15, 0x00,          //     LogicalMinimum(0)
    0x25, 0x01,          //     LogicalMaximum(1)
    0x75, 0x01,          //     ReportSize(1)
    0x81, 0x02,          //     Input(Data, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x75, 0x07,          //     ReportSize(7)
    0x81, 0x03,          //     Input(Constant, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x85, 0x0A,          //     ReportId(10)
    0x0A, 0x25, 0x02,    //     UsageId(AC Forward[0x0225])
    0x75, 0x01,          //     ReportSize(1)
    0x81, 0x02,          //     Input(Data, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x75, 0x07,          //     ReportSize(7)
    0x81, 0x03,          //     Input(Constant, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x85, 0x0B,          //     ReportId(11)
    0x09, 0xB6,          //     UsageId(Scan Previous Track[0x00B6])
    0x75, 0x01,          //     ReportSize(1)
    0x81, 0x02,          //     Input(Data, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x75, 0x07,          //     ReportSize(7)
    0x81, 0x03,          //     Input(Constant, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x85, 0x0C,          //     ReportId(12)
    0x09, 0xB5,          //     UsageId(Scan Next Track[0x00B5])
    0x75, 0x01,          //     ReportSize(1)
    0x81, 0x02,          //     Input(Data, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x75, 0x07,          //     ReportSize(7)
    0x81, 0x03,          //     Input(Constant, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x85, 0x0D,          //     ReportId(13)
    0x09, 0xB0,          //     UsageId(Play[0x00B0])
    0x75, 0x01,          //     ReportSize(1)
    0x81, 0x02,          //     Input(Data, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x75, 0x07,          //     ReportSize(7)
    0x81, 0x03,          //     Input(Constant, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x85, 0x0E,          //     ReportId(14)
    0x09, 0xB1,          //     UsageId(Pause[0x00B1])
    0x75, 0x01,          //     ReportSize(1)
    0x81, 0x02,          //     Input(Data, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x75, 0x07,          //     ReportSize(7)
    0x81, 0x03,          //     Input(Constant, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x85, 0x0F,          //     ReportId(15)
    0x09, 0xCD,          //     UsageId(Play/Pause[0x00CD])
    0x75, 0x01,          //     ReportSize(1)
    0x81, 0x02,          //     Input(Data, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x75, 0x07,          //     ReportSize(7)
    0x81, 0x03,          //     Input(Constant, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x85, 0x10,          //     ReportId(16)
    0x09, 0xE2,          //     UsageId(Mute[0x00E2])
    0x75, 0x01,          //     ReportSize(1)
    0x81, 0x02,          //     Input(Data, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x75, 0x07,          //     ReportSize(7)
    0x81, 0x03,          //     Input(Constant, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x85, 0x11,          //     ReportId(17)
    0x09, 0x78,          //     UsageId(Camera Access Toggle[0x0078])
    0x75, 0x01,          //     ReportSize(1)
    0x81, 0x02,          //     Input(Data, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x75, 0x07,          //     ReportSize(7)
    0x81, 0x03,          //     Input(Constant, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0xC0,                // EndCollection()
};
