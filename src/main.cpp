#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MyApp : public wxApp {
public:
  virtual bool OnInit();
};

class MyFrame : public wxFrame {
public:
  MyFrame();

private:
  void OnExit(wxCommandEvent &event);
  void OnSend(wxCommandEvent &event);
  wxTextCtrl *myTextCtrl;
  wxComboBox *myComboBox;
};

enum { ID_Hello = 1 };

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
  MyFrame *frame = new MyFrame();
  frame->Show(true);
  return true;
}

MyFrame::MyFrame()
    : wxFrame(NULL, wxID_ANY, "TinyClient - A really tiny REST Client") {

  wxPanel *panel = new wxPanel(this, wxID_ANY);
  wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

  // Combo Box
  wxString choices[] = {"GET", "POST"};
  myComboBox =
      new wxComboBox(panel, wxID_ANY, choices[0], wxPoint(10, 10),
                     wxSize(80, -1), WXSIZEOF(choices), choices, wxCB_READONLY);

  // Text Control
  myTextCtrl = new wxTextCtrl(panel, wxID_ANY, "http://", wxPoint(10, 50),
                              wxSize(200, -1));

  // Button
  wxButton *myButton = new wxButton(panel, wxID_ANY, "Send");
  myButton->Bind(wxEVT_BUTTON, &MyFrame::OnSend, this);

  hbox->Add(myComboBox, 0, wxALL, 2);
  hbox->Add(myTextCtrl, 0, wxALL, 2);

  vbox->Add(hbox, 0, wxALL, 2);
  vbox->Add(myButton, 0, wxALL, 2);

  panel->SetSizer(vbox);

  wxMenu *menuFile = new wxMenu;
  menuFile->Append(wxID_EXIT);
  wxMenuBar *menuBar = new wxMenuBar;
  menuBar->Append(menuFile, "&File");
  SetMenuBar(menuBar);

  CreateStatusBar();
  SetStatusText("TinyClient");

  Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
};

void MyFrame::OnExit(wxCommandEvent &event) { Close(true); };

void MyFrame::OnSend(wxCommandEvent &event) {
  wxString method = myComboBox->GetValue();
  wxString url = myTextCtrl->GetValue();
  
  wxMessageBox("Sending " + method + " request to " + url, "Request Send",
               wxOK | wxICON_INFORMATION);
}
