#include "GBR2STL.h"
#include <nana/gui.hpp>
#include <nana/gui/filebox.hpp>


GBR2STL::GBR2STL(): nana::form(nana::API::make_center(640, 480) , appear::decorate<appear::taskbar, appear::minimize>())
{
    init_();
}

GBR2STL::~GBR2STL()
{

}

void GBR2STL::clickedFrontCopper()
{
    nana::filebox fbox(*this, true);
    fbox.add_filter("Gerber File", "*.gbr , *.GBR");
    frontCopperPath = fbox.show() ? fbox.file() : "";
    frontCopperPathDisplay.caption(frontCopperPath);
}

void GBR2STL::clickedDrillFile()
{
    nana::filebox fbox(*this, true);
    fbox.add_filter("Gerber File", "*.gbr , *.GBR");
    drillFilePath = fbox.show() ? fbox.file() : "";
    drillFilePathDisplay.caption(drillFilePath);
}

void GBR2STL::clickedBoardOutline()
{
    nana::filebox fbox(*this, true);
    fbox.add_filter("Gerber File", "*.gbr , *.GBR");
    boardOutlinrPath = fbox.show() ? fbox.file() : "";
    boardOutlinePathDisplay.caption(boardOutlinrPath);
}

void GBR2STL::clickedOutputFile()
{
    nana::filebox fbox(*this, false);
    fbox.add_filter("STL File", "*.stl , *.STL");
    outputFilePath = fbox.show() ? fbox.file() : "";
    outputFilePathDisplay.caption(outputFilePath);
}

void GBR2STL::clickedConvert()
{

}

void GBR2STL::init_()
{
    _place.div("vert margin=5 gap=2 _field_");
    caption("Gerber to STL File Converter");
    // frontCopperGroup
    frontCopperGroup.create(*this);
    frontCopperGroup.caption_align(static_cast<nana::align>(0));
    frontCopperGroup.div("margin=5 gap=2 _field_");
    frontCopperGroup.caption("Front Copper");
    _place["_field_"] << frontCopperGroup;
    // frontCopperPathDisplay
    frontCopperPathDisplay.create(frontCopperGroup);
    frontCopperPathDisplay.caption("Please Pick a file");
    frontCopperGroup["_field_"] << frontCopperPathDisplay;
    // openFrontCopper
    openFrontCopper.create(frontCopperGroup);
    frontCopperGroup["_field_"] << openFrontCopper;
    openFrontCopper.caption("Open Front Copper");
    openFrontCopper.events().click([this]{clickedFrontCopper();});
    // drillFileGroup
    drillFileGroup.create(*this);
    drillFileGroup.caption_align(static_cast<nana::align>(0));
    drillFileGroup.div("margin=5 gap=2 _field_");
    drillFileGroup.caption("Drill File");
    _place["_field_"] << drillFileGroup;
    // drillFilePathDisplay
    drillFilePathDisplay.create(drillFileGroup);
    drillFilePathDisplay.caption("Please Pick a file");
    drillFileGroup["_field_"] << drillFilePathDisplay;
    // openDrillFile
    openDrillFile.create(drillFileGroup);
    drillFileGroup["_field_"] << openDrillFile;
    openDrillFile.caption("Open Drill File");
    openDrillFile.events().click([this]{clickedDrillFile();});
    // boardOutlineGroup
    boardOutlineGroup.create(*this);
    boardOutlineGroup.caption_align(static_cast<nana::align>(0));
    boardOutlineGroup.div("margin=5 gap=2 _field_");
    boardOutlineGroup.caption("Board Outline");
    _place["_field_"] << boardOutlineGroup;
    // boardOutlinePathDisplay
    boardOutlinePathDisplay.create(boardOutlineGroup);
    boardOutlinePathDisplay.caption("Please Pick a file");
    boardOutlineGroup["_field_"] << boardOutlinePathDisplay;
    // openBoardOutline
    openBoardOutline.create(boardOutlineGroup);
    boardOutlineGroup["_field_"] << openBoardOutline;
    openBoardOutline.caption("Open Board Outline");
    openBoardOutline.events().click([this]{clickedBoardOutline();});
    // outputFileGroup
    outputFileGroup.create(*this);
    outputFileGroup.caption_align(static_cast<nana::align>(0));
    outputFileGroup.div("margin=5 gap=2 _field_");
    outputFileGroup.caption("Output File");
    _place["_field_"] << outputFileGroup;
    // outputFilePathDisplay
    outputFilePathDisplay.create(outputFileGroup);
    outputFilePathDisplay.caption("Please Pick a file");
    outputFileGroup["_field_"] << outputFilePathDisplay;
    // openOutputFile
    openOutputFile.create(outputFileGroup);
    outputFileGroup["_field_"] << openOutputFile;
    openOutputFile.caption("Output File Path");
    openOutputFile.events().click([this]{clickedOutputFile();});
    // convert
    convert.create(*this);
    _place["_field_"] << convert;
    convert.caption("Convert!");
    convert.events().click([this]{clickedConvert();});

    _place.collocate();
    frontCopperGroup.collocate();
    drillFileGroup.collocate();
    boardOutlineGroup.collocate();
    outputFileGroup.collocate();
}

