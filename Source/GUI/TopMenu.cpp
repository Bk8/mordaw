/*
==============================================================================

TopMenu.cpp
Created: 2 Aug 2015 12:24:35pm
Author:  Thomas

==============================================================================
*/

#include "TopMenu.h"
#include "MainComponent.h"
#include "../Core/ProjectManager.h"
#include "../Audio/Engine.h"

TopMenu::TopMenu(ApplicationCommandManager& commandsManager) : MenuBarModel(), _commandsManager(commandsManager) {
    ApplicationCommandManager* commands = &_commandsManager;

    addFileMenu(commands);
    addEditMenu(commands);
    addViewMenu(commands);
    addTransportMenu(commands);

    menuItemsChanged();

    for (auto current = _menus.begin(), end = _menus.end(); current != end; ++current) {
        _menusNames.add(current->first);
    }
}

TopMenu::~TopMenu() {
}

void TopMenu::addFileMenu(ApplicationCommandManager* commands) {
    PopupMenu fileMenu;

    fileMenu.addCommandItem(commands, ProjectManager::newProject);
    fileMenu.addCommandItem(commands, ProjectManager::openProject);
    fileMenu.addCommandItem(commands, ProjectManager::saveProject);
    fileMenu.addCommandItem(commands, ProjectManager::saveProjectAs);
    fileMenu.addSeparator();
    fileMenu.addCommandItem(commands, StandardApplicationCommandIDs::quit);
    _menus.push_back(std::pair<String, PopupMenu>("File", fileMenu));
}

void TopMenu::addEditMenu(ApplicationCommandManager* commands) {
    PopupMenu editMenu;

    editMenu.addCommandItem(commands, StandardApplicationCommandIDs::undo);
    editMenu.addCommandItem(commands, StandardApplicationCommandIDs::redo);
    editMenu.addSeparator();
    editMenu.addCommandItem(commands, StandardApplicationCommandIDs::cut);
    editMenu.addCommandItem(commands, StandardApplicationCommandIDs::copy);
    editMenu.addCommandItem(commands, StandardApplicationCommandIDs::paste);
    _menus.push_back(std::pair<String, PopupMenu>("Edit", editMenu));
}

void TopMenu::addViewMenu(ApplicationCommandManager* commands) {
    PopupMenu viewMenu;
    
    viewMenu.addCommandItem(commands, MainComponent::showArrangement);
    viewMenu.addCommandItem(commands, MainComponent::showMixer);
    _menus.push_back(std::pair<String, PopupMenu>("View", viewMenu));
}

void TopMenu::addTransportMenu(ApplicationCommandManager* commands) {
    PopupMenu transportMenu;

    transportMenu.addCommandItem(commands, Audio::Engine::start);
    transportMenu.addCommandItem(commands, Audio::Engine::pause);
    transportMenu.addCommandItem(commands, Audio::Engine::stop);
    _menus.push_back(std::pair<String, PopupMenu>("Transport", transportMenu));
}


StringArray TopMenu::getMenuBarNames() {
    return _menusNames;
}

PopupMenu TopMenu::getMenuForIndex(int topLevelMenuIndex, const String& menuName) {
    for (auto it = _menus.begin(), end = _menus.end(); it != end; ++it) {
        if (it->first == menuName) {
            return it->second;
        }
    }

    return PopupMenu();
}

void TopMenu::menuItemSelected(int menuItemID, int topLevelMenuIndex) {
    
}
