#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MyApp : public wxApp {
public:
  virtual bool OnInit();
};

class MyFrame: public wxFrame {
public:
    MyFrame();

private:
    void OnExit(wxCommandEvent& event);
};

enum {ID_Hello = 1};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    MyFrame* frame = new MyFrame();
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(): wxFrame(NULL, wxID_ANY, "TinyClient - A really tiny REST Client") {
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(wxID_EXIT);

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("TinyClient");

    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
};

void MyFrame::OnExit(wxCommandEvent& event) {
    Close(true);
};

