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
    void OnClick(wxCommandEvent& event);
    wxTextCtrl* m_textCtrl;
};

enum {ID_Hello = 1};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    MyFrame* frame = new MyFrame();
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(): wxFrame(NULL, wxID_ANY, "TinyClient - A really tiny REST Client") {
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    wxBoxSizer* hbox = new wxBoxSizer(wxVERTICAL);

    m_textCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(10, -1));

    wxButton* button = new wxButton(panel, wxID_ANY, "Get Text");

    button->Bind(wxEVT_BUTTON, &MyFrame::OnClick, this);

    hbox->Add(m_textCtrl, 1, wxEXPAND | wxALL, 5);
    hbox->Add(button, 0, wxALL, 5);

    panel->SetSizer(hbox);

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

void MyFrame::OnClick(wxCommandEvent& event) {
    wxString text = m_textCtrl->GetValue();

    wxMessageBox("The text is the box is: \n" + text, "Text from box", wxOK | wxICON_INFORMATION);
};
