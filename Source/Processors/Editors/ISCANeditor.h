/*
    ------------------------------------------------------------------

    This file is part of the Open Ephys GUI
    Copyright (C) 2013 Open Ephys

    ------------------------------------------------------------------

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/


#ifndef __NETWORKEVENTSEDITOR_H_D6EC8B49__
#define __NETWORKEVENTSEDITOR_H_D6EC8B49__

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "GenericEditor.h"
#include "../Serial/ofSerial.h"
#include "VisualizerEditor.h"

class ISCANnode;


/**

  User interface for the "FileReader" source node.

  @see SourceNode, FileReaderThread

*/

class ISCANeditor;

class ISCANcanvas : public Visualizer

{
public:
    ISCANcanvas(ISCANeditor* ed,ISCANnode* n);
    ~ISCANcanvas();

    void paint(Graphics& g);

  //  void refresh();

	void beginAnimation() {}
	void endAnimation() {}
	
    void setParameter(int, float) {}
    void setParameter(int, int, int, float) {}
	
	void update() ;
	void refreshState() ;
	void refresh() ;

	void resized() ;

    void startRecording() { } // unused
    void stopRecording() { } // unused
    
    ISCANnode* processor;
	ISCANeditor* editor;
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ISCANcanvas);

};


class ISCANeditor : public VisualizerEditor,  public ComboBox::Listener
{
public:
    ISCANeditor(GenericProcessor* parentNode, bool useDefaultParameterEditors);
    virtual ~ISCANeditor();
	void refreshAnalogDevices();
    void buttonEvent(Button* button);
	void comboBoxChanged(ComboBox* comboBox);
    void collapsedStateChanged();
	Visualizer* createNewCanvas();
private:
	void refreshDevices();
	ScopedPointer<ToggleButton> communication;
    ScopedPointer<Label> gainX,gainY,gainXedt,gainYedt;
	ScopedPointer<UtilityButton> configButton,clearButton;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ISCANeditor);

};



#endif  // __NETWORKEVENTSEDITOR_H_D6EC8B49__
