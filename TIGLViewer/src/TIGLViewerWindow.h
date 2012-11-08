/*
* Copyright (C) 2007-2011 German Aerospace Center (DLR/SC)
*
* Created: 2010-08-13 Markus Litz <Markus.Litz@dlr.de>
* Changed: $Id: TIGLViewerWindow.h 203 2012-09-25 08:47:55Z martinsiggel $
*
* Version: $Revision: 203 $
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "TIGLViewerDocument.h"
#include "TIGLViewerContext.h"
#include "TIGLViewerWidget.h"
#include "TIGLViewerInputoutput.h"
#include "TIGLScriptEngine.h"

#include "ui_TIGLViewerWindow.h"

class QAction;
class QLabel;
class QMenu;
class QFileSystemWatcher;
class QShortcut;

class TIGLViewerWindow : public QMainWindow, private Ui::TIGLViewerWindow
{
    Q_OBJECT

public:
    enum { MaxRecentFiles = 5 };

    TIGLViewerWindow();
    ~TIGLViewerWindow();
	Handle_AIS_InteractiveContext& getContext() { return myVC->getContext(); };

	void setInitialCpacsFileName(QString filename);

	// Returns the Open CASCADE Widget and Context.
	TIGLViewerWidget* getMyOCC();

	// Displays a simple dialog for error messages
	void displayErrorMessage (const QString aMessage, QString aHeader);

public slots:
    void updateMenus(TiglCPACSConfigurationHandle);

private slots:
    void newFile();
    void open();
    void openRecentFile();
    void closeConfiguration();
    void save();
    void print();
	void setBackgroundImage();
    void undo();
    void redo();
    void cut();
    void copy();
    void paste();
    void about();
    void aboutQt();
	void xyzPosition (V3d_Coordinate X,
					  V3d_Coordinate Y,
					  V3d_Coordinate Z);
	void addPoint (V3d_Coordinate X,
				   V3d_Coordinate Y,
				   V3d_Coordinate Z);
	void statusMessage (const QString aMessage);

private:
    void createActions();
    void createMenus();
    void openFile(const QString&);
    void updateRecentFileActions();
    void setCurrentFile(const QString &);

    QAction *recentFileActions[MaxRecentFiles];

	// The OpenCASCADE context;
	TIGLViewerContext*  	myVC;

	QString 				myLastFolder;

	TIGLViewerDocument*		cpacsConfiguration;
	QString cpacsFileName;
	QString controlFileName;
	QFileSystemWatcher *watcher;
    class QDebugStream * stdoutStream, * errorStream;
    TIGLScriptEngine * scriptEngine;

};

#endif
