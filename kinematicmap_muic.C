void kinematicmap_muic()
{
  gStyle->SetOptStat(0);
  gStyle->SetHistLineColor(1);

  double beam_ion = 275.;
  double beam_muon_max = 960.;
  double beam_muon_min = 100.;

  double s_max = pow(beam_muon_max+beam_ion,2)-pow(beam_muon_max-beam_ion,2);
  double s_min = pow(beam_muon_min+beam_ion,2)-pow(beam_muon_min-beam_ion,2);

  TF1* x_ymin = new TF1("x_ymin","x/(pow([0]+[1],2)-pow([0]-[1],2))/[2]",0.1,10000000);
  TF1* x_ymax = new TF1("x_ymax","x/(pow([0]+[1],2)-pow([0]-[1],2))/[2]",0.1,10000000);
  x_ymin->FixParameter(1,275.);
  x_ymin->FixParameter(2,0.01);
  x_ymax->FixParameter(1,275.);
  x_ymax->FixParameter(2,0.95);

  TF1* Q2_ymin = new TF1("Q2_ymin","x*(pow([0]+[1],2)-pow([0]-[1],2))*[2]",0.0000001,1);
  TF1* Q2_ymax = new TF1("Q2_ymax","x*(pow([0]+[1],2)-pow([0]-[1],2))*[2]",0.0000001,1);
  Q2_ymin->FixParameter(1,275.);
  Q2_ymin->FixParameter(2,0.01);
  Q2_ymax->FixParameter(1,275.);
  Q2_ymax->FixParameter(2,0.95);

  x_ymin->SetParameter(0,beam_muon_max);
  x_ymax->SetParameter(0,beam_muon_max);
  Q2_ymin->SetParameter(0,beam_muon_max);
  Q2_ymax->SetParameter(0,beam_muon_max);
  double muicx_1[5] = {x_ymax->Eval(0.1+0.01),x_ymin->Eval(0.1+0.01),1.-0.01,1.-0.01,x_ymax->Eval(0.1+0.01)};
  double muicy_1[5] = {0.1+0.01,0.1+0.01,Q2_ymin->Eval(1.-0.01),Q2_ymax->Eval(1.-0.01),0.1+0.01};

  x_ymin->SetParameter(0,700);
  x_ymax->SetParameter(0,700);
  Q2_ymin->SetParameter(0,700);
  Q2_ymax->SetParameter(0,700);
  double muicx_2[5] = {x_ymax->Eval(0.1),x_ymin->Eval(0.1),1.,1.,x_ymax->Eval(0.1)};
  double muicy_2[5] = {0.1,0.1,Q2_ymin->Eval(1.),Q2_ymax->Eval(1.),0.1};

  x_ymin->SetParameters(920,27.6,0.01);
  x_ymax->SetParameters(920,27.6,0.95);
  Q2_ymin->SetParameters(920,27.6,0.01);
  Q2_ymax->SetParameters(920,27.6,0.95);
  double herax_1[5] = {x_ymax->Eval(0.1+0.01),x_ymin->Eval(0.1+0.01),1.-0.01,1.-0.01,x_ymax->Eval(0.1+0.01)};
  double heray_1[5] = {0.1+0.01,0.1+0.01,Q2_ymin->Eval(1.-0.01),Q2_ymax->Eval(1.-0.01),0.1+0.01};

  x_ymin->SetParameters(275,18,0.01);
  x_ymax->SetParameters(275,18,0.95);
  Q2_ymin->SetParameters(275,18,0.01);
  Q2_ymax->SetParameters(275,18,0.95);
  double eicx_1[5] = {x_ymax->Eval(0.1+0.01),x_ymin->Eval(0.1+0.01),1.-0.01,1.-0.01,x_ymax->Eval(0.1+0.01)};
  double eicy_1[5] = {0.1+0.01,0.1+0.01,Q2_ymin->Eval(1.-0.01),Q2_ymax->Eval(1.-0.01),0.1+0.01};

  x_ymin->SetParameters(7000,50,0.01);
  x_ymax->SetParameters(7000,50,0.95);
  Q2_ymin->SetParameters(7000,50,0.01);
  Q2_ymax->SetParameters(7000,50,0.95);
  double lhecx_1[5] = {x_ymax->Eval(0.1+0.01),x_ymin->Eval(0.1+0.01),1.-0.01,1.-0.01,x_ymax->Eval(0.1+0.01)};
  double lhecy_1[5] = {0.1+0.01,0.1+0.01,Q2_ymin->Eval(1.-0.01),Q2_ymax->Eval(1.-0.01),0.1+0.01};

  TGraph* gr_muic1 = new TGraph(5,muicx_1,muicy_1);
  gr_muic1->SetFillColorAlpha(kRed,0.3);
//  gr_muic1->SetFillColorAlpha(kGreen+2,0.3);
  gr_muic1->SetFillStyle(3315);
  gr_muic1->SetLineColor(kRed);
//  gr_muic1->SetLineColor(kGreen+2);
  gr_muic1->SetLineWidth(4);

  TGraph* gr_muic2 = new TGraph(5,muicx_2,muicy_2);
  gr_muic2->SetFillColorAlpha(kRed-4,0.2);
//  gr_muic2->SetFillStyle(3023);
  gr_muic2->SetLineColor(kRed-4);

  TGraph* gr_hera1 = new TGraph(5,herax_1,heray_1);
  gr_hera1->SetFillColorAlpha(kOrange-4,0.8);
//  gr_hera1->SetFillStyle(3023);
  gr_hera1->SetLineColor(kOrange-4);
  gr_hera1->SetLineWidth(0);

  TGraph* gr_eic1 = new TGraph(5,eicx_1,eicy_1);
  gr_eic1->SetFillColorAlpha(kGreen,0.2);
//  gr_eic1->SetFillColorAlpha(kRed-4,0.2);
  gr_eic1->SetFillStyle(3354);
  gr_eic1->SetLineColor(kGreen+1);
//  gr_eic1->SetLineColor(kRed-4);
  gr_eic1->SetLineWidth(3);

  TGraph* gr_lhec1 = new TGraph(5,lhecx_1,lhecy_1);
  gr_lhec1->SetFillColorAlpha(kBlue-8,0.2);
//  gr_lhec1->SetFillStyle(3354);
  gr_lhec1->SetLineColor(kBlue-9);
  gr_lhec1->SetLineWidth(3);


// Saturation scales
  TF1* sat_p = new TF1("sat_p","[0]*pow([2]/x,[1])",0.0000001,1);
  sat_p->SetParameters(1.0,0.29,3e-4);
  sat_p->SetLineStyle(9);
  sat_p->SetLineWidth(3);
  sat_p->SetLineColor(kRed);

  TF1* sat1_p = new TF1("sat1_p","[0]*pow([2]/x,[1])",0.0000001,1);
  sat1_p->SetParameters(1.0,0.277,0.41e-4);
  sat1_p->SetLineStyle(9);
 
/*
  double sat_p_x[] = {0.4e-5,0.4e-4,4e-4,4e-3,4e-2,4e-1};
  double sat_p_y[] = {2./pow(1.1,2),2./pow(1.6,2),2./pow(1.1,2),2./pow(1.1,2,2./pow(1.1,2,2./pow(1.1,2}
*/

  TLine* line = new TLine(0.0000001,1,1,1);
  line->SetLineStyle(9);
  line->SetLineWidth(1);

  TH2D* htmp = new TH2D("htmp",";x;Q^{2} (GeV^{2})",1000,0.0000001,1,1000,0.1,1800000);
  htmp->GetXaxis()->CenterTitle();
  htmp->GetYaxis()->CenterTitle();
  htmp->GetXaxis()->SetTitleSize(htmp->GetXaxis()->GetTitleSize()*1.4);
  htmp->GetYaxis()->SetTitleSize(htmp->GetYaxis()->GetTitleSize()*1.4);
  htmp->GetYaxis()->SetTitleOffset(0.8);

  TCanvas* c = new TCanvas("c","",700,500);
  c->SetLogy();
  c->SetLogx();
  c->SetRightMargin(0.02);
  c->SetTopMargin(0.06);
  c->SetBottomMargin(0.105);
  htmp->Draw();
  gr_hera1->Draw("LFsame");
  gr_eic1->Draw("LFsame");
  gr_lhec1->Draw("LFsame");
  gr_muic1->Draw("LFsame");
  sat_p->Draw("Lsame");
  line->Draw("Lsame");

  TLegend* legend = new TLegend(0.12,0.68,0.55,0.93);
  legend->SetFillColor(0);
  legend->SetBorderSize(0);
  legend->AddEntry(gr_muic1,Form("MuIC: #mu^{-} (%.0f) + p (275)",beam_muon_max),"F");
  legend->AddEntry(gr_lhec1,"LHeC: #it{e}^{-} (50) + p (7000)","F");
  legend->AddEntry(gr_hera1,"HERA: #it{e}^{-} (27.6) + p (920)","F");
  legend->AddEntry(gr_eic1,"EIC: #it{e}^{-} (18) + p (275)","F");
  legend->Draw("");

  TLatex* latex2 = new TLatex();
  latex2->SetNDC();
  latex2->SetTextFont(42);
  latex2->SetTextSize(latex2->GetTextSize()*0.9);
  latex2->DrawLatex(0.15,0.6,"0.01 < y < 0.95");

  TLatex* latex22 = new TLatex();
  latex22->SetNDC();
  latex22->SetTextFont(42);
  latex22->SetTextAngle(-12);
  latex22->SetTextSize(latex22->GetTextSize()*0.8);
  latex22->DrawLatex(0.12,0.35,"Q^{2}_{s,GBW}(x,proton)");

  TLatex* latex_new = new TLatex();
  latex_new->SetNDC();
  latex_new->SetTextFont(42);
  latex_new->SetTextColor(1);
  latex_new->SetTextSize(latex_new->GetTextSize()*0.75);
  latex_new->DrawLatex(0.8,0.24,"perturbative");
  latex_new->DrawLatex(0.8,0.18,"non-perturbative");

  TF1* func_acc[12];
  TF1* func1_acc[12];
  TF1* func2_acc[12];
  TF1* func3_acc[12];

  TF1* func_energy[12];
  TF1* func1_energy[12];
  TF1* func2_energy[12];
  TF1* func3_energy[12];

  for(int i=0;i<12;i++)
  {
// muic
    func_acc[i] = new TF1(Form("func_acc_%d",i),"x*(pow([0]+[1],2)-pow([0]-[1],2))/(1+x*[0]*exp(-2*[2])/[1])",0.0000001,1);
    func_acc[i]->SetParameters(275.,beam_muon_max,-7+i);
    func_acc[i]->SetLineColor(1);
    func_acc[i]->SetLineStyle(7);

    func1_acc[i] = new TF1(Form("func1_acc_%d",i),"x*(pow([0]+[1],2)-pow([0]-[1],2))/(1+[1]*exp(2*[2])/x/[0])",0.0000001,1);
    func1_acc[i]->SetParameters(275.,beam_muon_max,3-i);
    func1_acc[i]->SetLineColor(1);
    func1_acc[i]->SetLineStyle(7);

// lhec
    func2_acc[i] = new TF1(Form("func2_acc_%d",i),"x*(pow([0]+[1],2)-pow([0]-[1],2))/(1+x*[0]*exp(-2*[2])/[1])",0.0000001,1);
    func2_acc[i]->SetParameters(7000.,50.,-7+i);
    func2_acc[i]->SetLineColor(1);
    func2_acc[i]->SetLineStyle(7);

    func3_acc[i] = new TF1(Form("func3_acc_%d",i),"x*(pow([0]+[1],2)-pow([0]-[1],2))/(1+[1]*exp(2*[2])/x/[0])",0.0000001,1);
    func3_acc[i]->SetParameters(7000.,50.,5-i);
    func3_acc[i]->SetLineColor(1);
    func3_acc[i]->SetLineStyle(7);

// hera     
  }

  double haden_muic[] = {250,80,20,10,5,1};
  double lepen_muic[] = {930,600,400,50,10,5};
  double haden_lhec[] = {2500,800,200,40,15,5};
  double lepen_lhec[] = {48,35,10,5,60,120};

  for(int i=0;i<6;i++)
  { 
// muic
    func_energy[i] = new TF1(Form("func_energy_%d",i),"(1-[2]/[1])/(1/(x*(pow([0]+[1],2)-pow([0]-[1],2)))-1/(4*[1]*[1]))",0.0000001,1);
    func_energy[i]->SetParameters(275.,beam_muon_max,lepen_muic[i]);
    func_energy[i]->SetLineColor(1);
    func_energy[i]->SetLineStyle(10);

    func1_energy[i] = new TF1(Form("func1_energy_%d",i),"x*(pow([0]+[1],2)-pow([0]-[1],2))*(1-[2]/(x*[0]))/(1-[1]/(x*[0]))",0.0000001,1);
    func1_energy[i]->SetParameters(275.,beam_muon_max,haden_muic[i]);
    func1_energy[i]->SetLineColor(1);
    func1_energy[i]->SetLineStyle(10);

// lhec
    if(lepen_lhec[i]<50) func2_energy[i] = new TF1(Form("func2_energy_%d",i),"(1-[2]/[1])/(1/(x*(pow([0]+[1],2)-pow([0]-[1],2)))-1/(4.*[1]*[1]))",0.0000001,4.*50*50./(pow(50+7000.,2)-pow(7000.-50,2))/0.95*(0.95+lepen_lhec[i]/50.-1));
    else func2_energy[i] = new TF1(Form("func2_energy_%d",i),"(1-[2]/[1])/(1/(x*(pow([0]+[1],2)-pow([0]-[1],2)))-1/(4.*[1]*[1]))",4.*50*50./(pow(50+7000.,2)-pow(7000.-50,2))/0.95*(0.95+lepen_lhec[i]/50.-1),1);
    func2_energy[i]->SetParameters(7000.,50.,lepen_lhec[i]);
    func2_energy[i]->SetLineColor(1);
    func2_energy[i]->SetLineStyle(10);

    if(haden_lhec[i]>50.) func3_energy[i] = new TF1(Form("func3_energy_%d",i),"x*(pow([0]+[1],2)-pow([0]-[1],2))*(1-[2]/(x*[0]))/(1-[1]/(x*[0]))",50./7000,1);
    else func3_energy[i] = new TF1(Form("func3_energy_%d",i),"x*(pow([0]+[1],2)-pow([0]-[1],2))*(1-[2]/(x*[0]))/(1-[1]/(x*[0]))",0.0000001,50./7000); 
    func3_energy[i]->SetParameters(7000.,50.,haden_lhec[i]);
    func3_energy[i]->SetLineColor(1);
    func3_energy[i]->SetLineStyle(10);
  }

  TCanvas* c1 = new TCanvas("c1","",700,500);
  c1->SetLogy();
  c1->SetLogx();
  c1->SetTopMargin(0.06);
  c1->SetBottomMargin(0.105);
  htmp->Draw();
  gr_muic1->Draw("LFsame");
  line->Draw("Lsame");
  func_acc[0]->Draw("Lsame");
//  func_acc[1]->Draw("Lsame");
  func_acc[2]->Draw("Lsame");
//  func_acc[3]->Draw("Lsame");
  func_acc[4]->Draw("Lsame");
//  func_acc[5]->Draw("Lsame");
  func_acc[6]->Draw("Lsame");

//  func1_acc[0]->Draw("Lsame");
  func1_acc[1]->Draw("Lsame");
//  func1_acc[2]->Draw("Lsame");
  func1_acc[3]->Draw("Lsame");
//  func1_acc[4]->Draw("Lsame");
  func1_acc[5]->Draw("Lsame");
//  func1_acc[6]->Draw("Lsame");
  func1_acc[7]->Draw("Lsame");
  func1_acc[9]->Draw("Lsame");

  func_energy[0]->Draw("Lsame");
  func_energy[1]->Draw("Lsame");
//  func_energy[2]->Draw("Lsame");
//  func_energy[3]->Draw("Lsame");

  func1_energy[0]->Draw("Lsame");
  func1_energy[1]->Draw("Lsame");
  func1_energy[2]->Draw("Lsame");
//  func1_energy[3]->Draw("Lsame");
  func1_energy[4]->Draw("Lsame");

  TLegend* legend1 = new TLegend(0.12,0.78,0.6,0.88);
  legend1->SetFillColor(0);
  legend1->SetBorderSize(0);
  legend1->AddEntry(gr_muic1,Form("MuIC: #mu^{-} (%.0f) + p (275)",beam_muon_max),"F");
  legend1->Draw("");

  TLatex* latex = new TLatex();
  latex->SetNDC();
  latex->SetTextFont(42);
  latex->SetTextSize(latex->GetTextSize()*0.9);
  latex->DrawLatex(0.15,0.6,"0.01 < y < 0.95");
//  latex->SetTextColor(kRed);
  latex->SetTextSize(latex->GetTextSize()*0.8);
  latex->DrawLatex(0.91,0.26,"#eta^{f}_{#mu} = -7");
//  latex->DrawLatex(0.91,0.36,"#eta^{f}_{#mu} = -6");
  latex->DrawLatex(0.91,0.46,"#eta^{f}_{#mu} = -5");
//  latex->DrawLatex(0.91,0.56,"#eta^{f}_{#mu} = -4");
  latex->DrawLatex(0.91,0.665,"#eta^{f}_{#mu} = -3");
//  latex->DrawLatex(0.91,0.76,"#eta^{f}_{#mu} = -2");
  latex->DrawLatex(0.91,0.85,"#eta^{f}_{#mu} = -1");

  TLatex* latex3 = new TLatex();
  latex3->SetNDC();
  latex3->SetTextFont(42);
//  latex3->SetTextColor(kBlue);
  latex3->SetTextSize(latex3->GetTextSize()*0.7);
  latex3->SetTextAngle(50);
  latex3->DrawLatex(0.22,0.12,"#eta^{f}_{h} = -6");
  latex3->DrawLatex(0.325,0.12,"#eta^{f}_{h} = -4");
  latex3->DrawLatex(0.42,0.12,"#eta^{f}_{h} = -2");
  latex3->DrawLatex(0.52,0.12,"#eta^{f}_{h} = 0");
  latex3->DrawLatex(0.62,0.12,"#eta^{f}_{h} = 2");

  TLatex* latex5 = new TLatex();
  latex5->SetNDC();
  latex5->SetTextFont(42);
//  latex5->SetTextColor(kRed);
  latex5->SetTextSize(latex5->GetTextSize()*0.7);
  latex5->SetTextAngle(35);
  latex5->DrawLatex(0.665,0.51,"E^{f}_{#mu} = 930");
  latex5->DrawLatex(0.67,0.64,"E^{f}_{#mu} = 600");

  TLatex* latex7 = new TLatex();
  latex7->SetNDC();
  latex7->SetTextFont(42);
//  latex7->SetTextColor(kBlue);
  latex7->SetTextSize(latex7->GetTextSize()*0.7);
  latex7->SetTextAngle(90);
  latex7->DrawLatex(0.885,0.23,"E^{f}_{h} = 250");
  latex7->DrawLatex(0.83,0.23,"E^{f}_{h} = 80");
  latex7->DrawLatex(0.765,0.23,"E^{f}_{h} = 20");


  TCanvas* c1a = new TCanvas("c1a","",700,500);
  c1a->SetLogy();
  c1a->SetLogx();
  c1a->SetTopMargin(0.06);
  c1a->SetBottomMargin(0.105);
  htmp->Draw();
  gr_muic1->Draw("LFsame");
  line->Draw("Lsame");

  func_acc[0]->Draw("Lsame");
  func_acc[1]->Draw("Lsame");
  func_acc[2]->Draw("Lsame");
  func_acc[3]->Draw("Lsame");
  func_acc[4]->Draw("Lsame");
  func_acc[5]->Draw("Lsame");
  func_acc[6]->Draw("Lsame");

  func_energy[0]->Draw("Lsame");
  func_energy[1]->Draw("Lsame");

  sat_p->Draw("Lsame");
  latex22->DrawLatex(0.12,0.35,"Q^{2}_{s,GBW}(x,proton)");

  legend1->Draw("");

  TLatex* latexa = new TLatex();
  latexa->SetNDC();
  latexa->SetTextFont(42);
  latexa->SetTextSize(latexa->GetTextSize()*0.9);
  latexa->DrawLatex(0.15,0.6,"0.01 < y < 0.95");
//  latexa->SetTextColor(kRed);
  latexa->SetTextSize(latexa->GetTextSize()*0.8);
  latexa->DrawLatex(0.91,0.26,"#eta^{f}_{#mu} = -7");
  latexa->DrawLatex(0.91,0.365,"#eta^{f}_{#mu} = -6");
  latexa->DrawLatex(0.91,0.46,"#eta^{f}_{#mu} = -5");
  latexa->DrawLatex(0.91,0.565,"#eta^{f}_{#mu} = -4");
  latexa->DrawLatex(0.91,0.665,"#eta^{f}_{#mu} = -3");
  latexa->DrawLatex(0.91,0.765,"#eta^{f}_{#mu} = -2");
  latexa->DrawLatex(0.91,0.85,"#eta^{f}_{#mu} = -1");

  TLatex* latex5a = new TLatex();
  latex5a->SetNDC();
  latex5a->SetTextFont(42);
//  latex5a->SetTextColor(kRed);
  latex5a->SetTextSize(latex5a->GetTextSize()*0.7);
  latex5a->SetTextAngle(35);
  latex5a->DrawLatex(0.665,0.51,"E^{f}_{#mu} = 930");
  latex5a->DrawLatex(0.62,0.59,"E^{f}_{#mu} = 600");

  TCanvas* c1b = new TCanvas("c1b","",700,500);
  c1b->SetLogy();
  c1b->SetLogx();
  c1b->SetTopMargin(0.06);
  c1b->SetBottomMargin(0.105);
  htmp->Draw();
  gr_muic1->Draw("LFsame");
  line->Draw("Lsame");

  func1_acc[1]->Draw("Lsame");
  func1_acc[3]->Draw("Lsame");
  func1_acc[5]->Draw("Lsame");
  func1_acc[7]->Draw("Lsame");
  func1_acc[9]->Draw("Lsame");

  func1_energy[0]->Draw("Lsame");
  func1_energy[1]->Draw("Lsame");
  func1_energy[2]->Draw("Lsame");
  func1_energy[4]->Draw("Lsame");

  sat_p->Draw("Lsame");
  latex22->DrawLatex(0.12,0.35,"Q^{2}_{s,GBW}(x,proton)");

  legend1->Draw("");

  TLatex* latex3b = new TLatex();
  latex3b->SetNDC();
  latex3b->SetTextFont(42);
  latex3b->SetTextSize(latex3b->GetTextSize()*0.9);
  latex3b->DrawLatex(0.15,0.6,"0.01 < y < 0.95");
  latex3b->SetTextSize(latex3b->GetTextSize()/0.9);
//  latex3b->SetTextColor(kBlue);
  latex3b->SetTextSize(latex3b->GetTextSize()*0.7);
  latex3b->SetTextAngle(50);
  latex3b->DrawLatex(0.22,0.12,"#eta^{f}_{h} = -6");
  latex3b->DrawLatex(0.325,0.12,"#eta^{f}_{h} = -4");
  latex3b->DrawLatex(0.42,0.12,"#eta^{f}_{h} = -2");
  latex3b->DrawLatex(0.52,0.12,"#eta^{f}_{h} = 0");
  latex3b->DrawLatex(0.62,0.12,"#eta^{f}_{h} = 2");

  TLatex* latex7b = new TLatex();
  latex7b->SetNDC();
  latex7b->SetTextFont(42);
//  latex7b->SetTextColor(kBlue);
  latex7b->SetTextSize(latex7b->GetTextSize()*0.7);
  latex7b->SetTextAngle(90);
  latex7b->DrawLatex(0.885,0.23,"E^{f}_{h} = 250");
  latex7b->DrawLatex(0.83,0.23,"E^{f}_{h} = 80");
  latex7b->DrawLatex(0.765,0.23,"E^{f}_{h} = 20");
  latex7b->DrawLatex(0.685,0.23,"E^{f}_{h} = 5");

  TCanvas* c2 = new TCanvas("c2","",700,500);
  c2->SetLogy();
  c2->SetLogx();
  c2->SetTopMargin(0.06);
  c2->SetBottomMargin(0.105);
  htmp->Draw();
  gr_lhec1->Draw("LFsame");
  line->Draw("Lsame");
//  func2_acc[0]->Draw("Lsame");
//  func2_acc[1]->Draw("Lsame");
//  func2_acc[2]->Draw("Lsame");
  func2_acc[3]->Draw("Lsame");
//  func2_acc[4]->Draw("Lsame");
  func2_acc[5]->Draw("Lsame");
//  func2_acc[6]->Draw("Lsame");
  func2_acc[7]->Draw("Lsame");
//  func2_acc[8]->Draw("Lsame");
  func2_acc[9]->Draw("Lsame");

//  func3_acc[0]->Draw("Lsame");
  func3_acc[1]->Draw("Lsame");
//  func3_acc[2]->Draw("Lsame");
  func3_acc[3]->Draw("Lsame");
//  func3_acc[4]->Draw("Lsame");
  func3_acc[5]->Draw("Lsame");
//  func3_acc[6]->Draw("Lsame");
  func3_acc[7]->Draw("Lsame");
  func3_acc[9]->Draw("Lsame");

  func2_energy[0]->Draw("Lsame");
  func2_energy[1]->Draw("Lsame");
//  func2_energy[2]->Draw("Lsame");
//  func2_energy[3]->Draw("Lsame");

  func3_energy[0]->Draw("Lsame");
  func3_energy[1]->Draw("Lsame");
  func3_energy[2]->Draw("Lsame");
  func3_energy[3]->Draw("Lsame");
  func3_energy[4]->Draw("Lsame");

  TLegend* legend2 = new TLegend(0.12,0.78,0.6,0.88);
  legend2->SetFillColor(0);
  legend2->SetBorderSize(0);
  legend2->AddEntry(gr_lhec1,"LHeC: #it{e}^{-} (50) + p (7000)","F");
  legend2->Draw("");

  TLatex* latex4 = new TLatex();
  latex4->SetNDC();
  latex4->SetTextFont(42);
  latex4->SetTextSize(latex4->GetTextSize()*0.9);
  latex4->DrawLatex(0.15,0.6,"0.01 < y < 0.95");
//  latex4->SetTextColor(kRed);
  latex4->SetTextSize(latex4->GetTextSize()*0.8);
  latex4->DrawLatex(0.91,0.275,"#eta^{f}_{e} = -4");
  latex4->DrawLatex(0.91,0.475,"#eta^{f}_{e} = -2");
  latex4->DrawLatex(0.91,0.675,"#eta^{f}_{e} = 0");
  latex4->DrawLatex(0.91,0.86,"#eta^{f}_{e} = 2");

  TLatex* latex6 = new TLatex();
  latex6->SetNDC();
  latex6->SetTextFont(42);
//  latex6->SetTextColor(kBlue);
  latex6->SetTextSize(latex6->GetTextSize()*0.7);
  latex6->SetTextAngle(50);
  latex6->DrawLatex(0.165,0.12,"#eta^{f}_{h} = -4");
  latex6->DrawLatex(0.26,0.12,"#eta^{f}_{h} = -2");
  latex6->DrawLatex(0.36,0.12,"#eta^{f}_{h} = 0");
  latex6->DrawLatex(0.455,0.12,"#eta^{f}_{h} = 2");
  latex6->DrawLatex(0.555,0.12,"#eta^{f}_{h} = 4");

  TLatex* latex8 = new TLatex();
  latex8->SetNDC();
  latex8->SetTextFont(42);
//  latex8->SetTextColor(kRed);
  latex8->SetTextSize(latex8->GetTextSize()*0.7);
  latex8->SetTextAngle(35);
  latex8->DrawLatex(0.43,0.3,"E^{f}_{e} = 48");
  latex8->DrawLatex(0.39,0.36,"E^{f}_{e} = 35");

  TLatex* latex10 = new TLatex();
  latex10->SetNDC();
  latex10->SetTextFont(42);
//  latex10->SetTextColor(kBlue);
  latex10->SetTextSize(latex10->GetTextSize()*0.7);
  latex10->SetTextAngle(90);
  latex10->DrawLatex(0.83,0.23,"E^{f}_{h} = 2500");
  latex10->DrawLatex(0.775,0.23,"E^{f}_{h} = 800");
  latex10->DrawLatex(0.715,0.23,"E^{f}_{h} = 200");
  latex10->DrawLatex(0.635,0.23,"E^{f}_{h} = 40");
  latex10->DrawLatex(0.585,0.23,"E^{f}_{h} = 15");

  TCanvas* c2a = new TCanvas("c2a","",700,500);
  c2a->SetLogy();
  c2a->SetLogx();
  c2a->SetTopMargin(0.06);
  c2a->SetBottomMargin(0.105);
  htmp->Draw();
  gr_lhec1->Draw("LFsame");
  line->Draw("Lsame");

//  func2_acc[0]->Draw("Lsame");
//  func2_acc[1]->Draw("Lsame");
//  func2_acc[2]->Draw("Lsame");
  func2_acc[3]->Draw("Lsame");
  func2_acc[4]->Draw("Lsame");
  func2_acc[5]->Draw("Lsame");
  func2_acc[6]->Draw("Lsame");
  func2_acc[7]->Draw("Lsame");
  func2_acc[8]->Draw("Lsame");
  func2_acc[9]->Draw("Lsame");

  func2_energy[0]->Draw("Lsame");
  func2_energy[1]->Draw("Lsame");
  func2_energy[4]->Draw("Lsame");
  func2_energy[5]->Draw("Lsame");

  legend2->Draw("");

  TLatex* latex4a = new TLatex();
  latex4a->SetNDC();
  latex4a->SetTextFont(42);
  latex4a->SetTextSize(latex4a->GetTextSize()*0.9);
  latex4a->DrawLatex(0.15,0.6,"0.01 < y < 0.95");
//  latex4a->SetTextColor(kRed);
  latex4a->SetTextSize(latex4a->GetTextSize()*0.8);
  latex4a->DrawLatex(0.91,0.275,"#eta^{f}_{e} = -4");
  latex4a->DrawLatex(0.91,0.37,"#eta^{f}_{e} = -3");
  latex4a->DrawLatex(0.91,0.475,"#eta^{f}_{e} = -2");
  latex4a->DrawLatex(0.91,0.57,"#eta^{f}_{e} = -1");
  latex4a->DrawLatex(0.91,0.675,"#eta^{f}_{e} = 0");
  latex4a->DrawLatex(0.91,0.77,"#eta^{f}_{e} = 1");
  latex4a->DrawLatex(0.91,0.86,"#eta^{f}_{e} = 2");

  TLatex* latex8a = new TLatex();
  latex8a->SetNDC();
  latex8a->SetTextFont(42);
//  latex8a->SetTextColor(kRed);
  latex8a->SetTextSize(latex8a->GetTextSize()*0.7);
  latex8a->SetTextAngle(35);
  latex8a->DrawLatex(0.43,0.3,"E^{f}_{e} = 48");
  latex8a->DrawLatex(0.39,0.36,"E^{f}_{e} = 35");
  latex8a->SetTextAngle(0);
  latex8a->DrawLatex(0.73,0.62,"E^{f}_{e} = 60");
  latex8a->DrawLatex(0.76,0.71,"E^{f}_{e} = 120");

  sat_p->Draw("Lsame");
  latex22->DrawLatex(0.12,0.35,"Q^{2}_{s,GBW}(x,proton)");

  TCanvas* c2b = new TCanvas("c2b","",700,500);
  c2b->SetLogy();
  c2b->SetLogx();
  c2b->SetTopMargin(0.06);
  c2b->SetBottomMargin(0.105);
  htmp->Draw();
  gr_lhec1->Draw("LFsame");
  line->Draw("Lsame");

  func3_acc[1]->Draw("Lsame");
  func3_acc[3]->Draw("Lsame");
  func3_acc[5]->Draw("Lsame");
  func3_acc[7]->Draw("Lsame");
  func3_acc[9]->Draw("Lsame");

  func3_energy[0]->Draw("Lsame");
  func3_energy[1]->Draw("Lsame");
  func3_energy[2]->Draw("Lsame");
  func3_energy[3]->Draw("Lsame");
  func3_energy[4]->Draw("Lsame");
  func3_energy[5]->Draw("Lsame");

  sat_p->Draw("Lsame");
  latex22->DrawLatex(0.12,0.35,"Q^{2}_{s,GBW}(x,proton)");

  legend2->Draw("");

  TLatex* latex6b = new TLatex();
  latex6b->SetNDC();
  latex6b->SetTextFont(42);
  latex6b->SetTextSize(latex6b->GetTextSize()*0.9);
  latex6b->DrawLatex(0.15,0.6,"0.01 < y < 0.95");
  latex6b->SetTextSize(latex6b->GetTextSize()/0.9);
//  latex6b->SetTextColor(kBlue);
  latex6b->SetTextSize(latex6b->GetTextSize()*0.7);
  latex6b->SetTextAngle(50);
  latex6b->DrawLatex(0.165,0.12,"#eta^{f}_{h} = -4");
  latex6b->DrawLatex(0.26,0.12,"#eta^{f}_{h} = -2");
  latex6b->DrawLatex(0.36,0.12,"#eta^{f}_{h} = 0");
  latex6b->DrawLatex(0.455,0.12,"#eta^{f}_{h} = 2");
  latex6b->DrawLatex(0.555,0.12,"#eta^{f}_{h} = 4");

  TLatex* latex10b = new TLatex();
  latex10b->SetNDC();
  latex10b->SetTextFont(42);
//  latex10b->SetTextColor(kBlue);
  latex10b->SetTextSize(latex10b->GetTextSize()*0.7);
  latex10b->SetTextAngle(90);
  latex10b->DrawLatex(0.84,0.23,"E^{f}_{h} = 2500");
  latex10b->DrawLatex(0.78,0.23,"E^{f}_{h} = 800");
  latex10b->DrawLatex(0.715,0.23,"E^{f}_{h} = 200");
  latex10b->DrawLatex(0.635,0.23,"E^{f}_{h} = 40");
  latex10b->DrawLatex(0.585,0.23,"E^{f}_{h} = 15");
  latex10b->DrawLatex(0.525,0.23,"E^{f}_{h} = 5");


  c->Print(Form("Q2vsx_allcolliders_mu%.0f.pdf",beam_muon_max));
  c->Print(Form("Q2vsx_allcolliders_mu%.0f.png",beam_muon_max));
  c1a->Print(Form("Q2vsx_muic_e_mu%.0f.pdf",beam_muon_max));
  c1a->Print(Form("Q2vsx_muic_e_mu%.0f.png",beam_muon_max));
  c1b->Print(Form("Q2vsx_muic_h_mu%.0f.pdf",beam_muon_max));
  c1b->Print(Form("Q2vsx_muic_h_mu%.0f.png",beam_muon_max));
  c2a->Print("Q2vsx_lhec_e.pdf");
  c2a->Print("Q2vsx_lhec_e.png");
  c2b->Print("Q2vsx_lhec_h.pdf");
  c2b->Print("Q2vsx_lhec_h.png");

/*
  c->Print("Q2vsx_allcolliders_alt.pdf");
  c->Print("Q2vsx_allcolliders_alt.png");
  c1->Print("Q2vsx_muic_alt.pdf");
  c1->Print("Q2vsx_muic_alt.png");
  c1a->Print("Q2vsx_muic_e_alt.pdf");
  c1a->Print("Q2vsx_muic_e_alt.png");
  c1b->Print("Q2vsx_muic_h_alt.pdf");
  c1b->Print("Q2vsx_muic_h_alt.png");
  c2->Print("Q2vsx_lhec_alt.pdf");
  c2->Print("Q2vsx_lhec_alt.png");
  c2a->Print("Q2vsx_lhec_e_alt.pdf");
  c2a->Print("Q2vsx_lhec_e_alt.png");
  c2b->Print("Q2vsx_lhec_h_alt.pdf");
  c2b->Print("Q2vsx_lhec_h_alt.png");
*/
}
