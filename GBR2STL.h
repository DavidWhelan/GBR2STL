#ifndef GBR2STL_H
#define GBR2STL_H

#include <nana/gui.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/widgets/group.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/label.hpp>

class GBR2STL : public nana::form
{
public:

GBR2STL();

~GBR2STL();


private:

std::string frontCopperPath = "";
std::string drillFilePath = "";
std::string boardOutlinrPath = "";
std::string outputFilePath = "";

void init_();

void clickedFrontCopper();
void clickedDrillFile();
void clickedBoardOutline();
void clickedOutputFile();
void clickedConvert();

protected:
	nana::place _place{ *this };
	nana::group frontCopperGroup;
	nana::label frontCopperPathDisplay;
	nana::button openFrontCopper;
	nana::group drillFileGroup;
	nana::label drillFilePathDisplay;
	nana::button openDrillFile;
	nana::group boardOutlineGroup;
	nana::label boardOutlinePathDisplay;
	nana::button openBoardOutline;
	nana::group outputFileGroup;
	nana::label outputFilePathDisplay;
	nana::button openOutputFile;
	nana::button convert;


	//<*declarations

	//*>
};

#endif //GBR2STL_H

