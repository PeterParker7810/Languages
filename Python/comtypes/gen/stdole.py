from enum import IntFlag

import comtypes.gen._00020430_0000_0000_C000_000000000046_0_2_0 as __wrapper_module__
from comtypes.gen._00020430_0000_0000_C000_000000000046_0_2_0 import (
    OLE_YPOS_HIMETRIC, StdFont, OLE_XSIZE_PIXELS, _lcid, VgaColor,
    GUID, EXCEPINFO, COMMETHOD, HRESULT, IPictureDisp, VARIANT_BOOL,
    OLE_OPTEXCLUSIVE, OLE_XSIZE_HIMETRIC, FONTITALIC, StdPicture,
    FONTNAME, FONTSIZE, IFont, Color, CoClass, IFontDisp,
    typelib_path, OLE_XPOS_CONTAINER, DISPMETHOD, OLE_COLOR,
    OLE_CANCELBOOL, _check_version, OLE_XPOS_PIXELS,
    OLE_ENABLEDEFAULTBOOL, IDispatch, Monochrome, OLE_YPOS_CONTAINER,
    dispid, IEnumVARIANT, IPicture, OLE_YSIZE_PIXELS, Gray,
    FONTUNDERSCORE, BSTR, IUnknown, OLE_YSIZE_HIMETRIC, Checked,
    Picture, FONTBOLD, OLE_XSIZE_CONTAINER, Unchecked,
    IFontEventsDisp, OLE_YSIZE_CONTAINER, DISPPARAMS,
    FONTSTRIKETHROUGH, DISPPROPERTY, Default, Font, OLE_YPOS_PIXELS,
    Library, OLE_XPOS_HIMETRIC, FontEvents, OLE_HANDLE
)


class OLE_TRISTATE(IntFlag):
    Unchecked = 0
    Checked = 1
    Gray = 2


class LoadPictureConstants(IntFlag):
    Default = 0
    Monochrome = 1
    VgaColor = 2
    Color = 4


__all__ = [
    'OLE_YPOS_HIMETRIC', 'OLE_YPOS_CONTAINER', 'StdFont', 'IPicture',
    'OLE_YSIZE_PIXELS', 'OLE_XSIZE_PIXELS', 'Gray', 'VgaColor',
    'FONTUNDERSCORE', 'IPictureDisp', 'OLE_YSIZE_HIMETRIC', 'Checked',
    'OLE_OPTEXCLUSIVE', 'OLE_XSIZE_HIMETRIC', 'FONTITALIC',
    'StdPicture', 'Picture', 'FONTBOLD', 'FONTNAME',
    'OLE_XSIZE_CONTAINER', 'LoadPictureConstants', 'FONTSIZE',
    'Unchecked', 'IFont', 'OLE_TRISTATE', 'Color', 'IFontEventsDisp',
    'OLE_YSIZE_CONTAINER', 'IFontDisp', 'typelib_path',
    'FONTSTRIKETHROUGH', 'OLE_XPOS_CONTAINER', 'OLE_COLOR',
    'OLE_CANCELBOOL', 'Default', 'Font', 'OLE_YPOS_PIXELS',
    'OLE_XPOS_PIXELS', 'Library', 'OLE_XPOS_HIMETRIC', 'FontEvents',
    'OLE_ENABLEDEFAULTBOOL', 'Monochrome', 'OLE_HANDLE'
]

