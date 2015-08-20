/*
  ==============================================================================

    LeftSide.h
    Created: 4 Aug 2015 7:58:42pm
    Author:  Thomas

  ==============================================================================
*/

#ifndef LEFTSIDE_H_INCLUDED
#define LEFTSIDE_H_INCLUDED

#include "TransportControls.h"
#include "ProjectTab.h"

//==============================================================================
/*
*/
class LeftSide    : public Component
{
public:
    LeftSide(ApplicationCommandManager &commands, const Audio::Engine &engine);
	~LeftSide();

	void prepareFileTree();

	void preparePluginList();

	void addTabs();

    void paint (Graphics&);
    void resized();

private:
    ApplicationCommandManager &_commands;

	TimeSliceThread _tsThread;
	DirectoryContentsList _directoryList;

	const Audio::Engine &_engine;
	AudioFormatManager _formats;
	KnownPluginList _plugins;
	
	ScopedPointer<TabbedComponent> _tabbedComponent;
	ScopedPointer<FileTreeComponent> _fileTree;
	ScopedPointer<ProjectTab> _projectTab;
	ScopedPointer<PluginListComponent> _pluginList;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LeftSide)
};


#endif  // LEFTSIDE_H_INCLUDED
