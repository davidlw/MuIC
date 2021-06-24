void kinematicmap_muic_ion()
{
  gStyle->SetOptStat(0);

  double beam_ion = 110.;
  double beam_muon_max = 960.;
  double beam_muon_min = 100.;

  double s_max = pow(beam_muon_max+beam_ion,2)-pow(beam_muon_max-beam_ion,2);
  double s_min = pow(beam_muon_min+beam_ion,2)-pow(beam_muon_min-beam_ion,2);

  TF1* x_ymin = new TF1("x_ymin","x/(pow([0]+[1],2)-pow([0]-[1],2))/[2]",0.1,10000000);
  TF1* x_ymax = new TF1("x_ymax","x/(pow([0]+[1],2)-pow([0]-[1],2))/[2]",0.1,10000000);
  x_ymin->FixParameter(1,beam_ion);
  x_ymin->FixParameter(2,0.01);
  x_ymax->FixParameter(1,beam_ion);
  x_ymax->FixParameter(2,0.95);

  TF1* Q2_ymin = new TF1("Q2_ymin","x*(pow([0]+[1],2)-pow([0]-[1],2))*[2]",0.0000001,1);
  TF1* Q2_ymax = new TF1("Q2_ymax","x*(pow([0]+[1],2)-pow([0]-[1],2))*[2]",0.0000001,1);
  Q2_ymin->FixParameter(1,beam_ion);
  Q2_ymin->FixParameter(2,0.01);
  Q2_ymax->FixParameter(1,beam_ion);
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
  double muicx_2[5] = {x_ymax->Eval(0.1+0.01),x_ymin->Eval(0.1+0.01),1.-0.01,1.-0.01,x_ymax->Eval(0.1+0.01)};
  double muicy_2[5] = {0.1+0.01,0.1+0.01,Q2_ymin->Eval(1.-0.01),Q2_ymax->Eval(1.-0.01),0.1+0.01};

  x_ymin->SetParameter(0,330);
  x_ymax->SetParameter(0,330);
  Q2_ymin->SetParameter(0,330);
  Q2_ymax->SetParameter(0,330);
  double muicx_3[5] = {x_ymax->Eval(0.1+0.01),x_ymin->Eval(0.1+0.01),1.-0.01,1.-0.01,x_ymax->Eval(0.1+0.01)};
  double muicy_3[5] = {0.1+0.01,0.1+0.01,Q2_ymin->Eval(1.-0.01),Q2_ymax->Eval(1.-0.01),0.1+0.01};

  x_ymin->SetParameters(beam_ion,18,0.01);
  x_ymax->SetParameters(beam_ion,18,0.95);
  Q2_ymin->SetParameters(beam_ion,18,0.01);
  Q2_ymax->SetParameters(beam_ion,18,0.95);
  double eicx_1[5] = {x_ymax->Eval(0.1+0.01),x_ymin->Eval(0.1+0.01),1.-0.01,1.-0.01,x_ymax->Eval(0.1+0.01)};
  double eicy_1[5] = {0.1+0.01,0.1+0.01,Q2_ymin->Eval(1.-0.01),Q2_ymax->Eval(1.-0.01),0.1+0.01};

  x_ymin->SetParameters(2750,50,0.01);
  x_ymax->SetParameters(2750,50,0.95);
  Q2_ymin->SetParameters(2750,50,0.01);
  Q2_ymax->SetParameters(2750,50,0.95);
  double lhecx_1[5] = {x_ymax->Eval(0.1+0.01),x_ymin->Eval(0.1+0.01),1.-0.01,1.-0.01,x_ymax->Eval(0.1+0.01)};
  double lhecy_1[5] = {0.1+0.01,0.1+0.01,Q2_ymin->Eval(1.0-0.01),Q2_ymax->Eval(1.-0.01),0.1+0.01};

  TGraph* gr_muic1 = new TGraph(5,muicx_1,muicy_1);
  gr_muic1->SetFillColorAlpha(kRed,0.3);
  gr_muic1->SetFillStyle(3315);
  gr_muic1->SetLineColor(kRed);
  gr_muic1->SetLineWidth(4);

  TGraph* gr_muic2 = new TGraph(5,muicx_2,muicy_2);
  gr_muic2->SetFillColorAlpha(kRed-4,0.2);
//  gr_muic2->SetFillStyle(3023);
  gr_muic2->SetLineColor(kRed-4);

  TGraph* gr_eic1 = new TGraph(5,eicx_1,eicy_1);
  gr_eic1->SetFillColorAlpha(kGreen,0.2);
  gr_eic1->SetFillStyle(3354);
  gr_eic1->SetLineColor(kGreen+1);
  gr_eic1->SetLineWidth(3);

  TGraph* gr_lhec1 = new TGraph(5,lhecx_1,lhecy_1);
  gr_lhec1->SetFillColorAlpha(kBlue-8,0.2);
//  gr_lhec1->SetFillStyle(3354);
  gr_lhec1->SetLineColor(kBlue-9);
  gr_lhec1->SetLineWidth(3);

  TF1* sat_A = new TF1("sat_A","[0]*pow([2]/x,[1])*pow([3],1./3)",0.0000005,1);
  sat_A->SetParameters(1.0,0.277,0.41e-4,197.);
  sat_A->SetLineStyle(9);
  sat_A->SetLineWidth(3);
  sat_A->SetLineColor(kRed);

  TLine* line = new TLine(0.0000005,1,1,1);
  line->SetLineStyle(9);
  line->SetLineWidth(1);

  TH2D* htmp = new TH2D("htmp",";x;Q^{2} (GeV^{2})",100,0.0000005,1,1000,0.1,1800000);
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
  gr_muic1->Draw("LFsame");
  gr_eic1->Draw("LFsame");
  gr_lhec1->Draw("LFsame");
//  gr_muic3->Draw("LFsame");
//  gr_muic2->Draw("LFsame");
  gr_muic1->Draw("LFsame");
  sat_A->Draw("Lsame");
  line->Draw("Lsame");

  TLegend* legend = new TLegend(0.12,0.71,0.55,0.91);
  legend->SetFillColor(0);
  legend->SetBorderSize(0);
  legend->AddEntry(gr_muic1,Form("MuIC: #mu^{-} (%.0f) + A (%.0f)",beam_muon_max,beam_ion),"F");
  legend->AddEntry(gr_eic1,"EIC: #it{e}^{-} (18) + A (110)","F");
  legend->AddEntry(gr_lhec1,"LHeC: #it{e}^{-} (50) + A (2750)","F");
  legend->Draw("");

  TLatex* latex2 = new TLatex();
  latex2->SetNDC();
  latex2->SetTextFont(42);
  latex2->SetTextSize(latex2->GetTextSize()*0.9);
  latex2->DrawLatex(0.15,0.6,"0.01 < y < 0.95");

  TLatex* latex22 = new TLatex();
  latex22->SetNDC();
  latex22->SetLineColor(1);
  latex22->SetTextFont(42);
  latex22->SetTextAngle(-10);
  latex22->SetTextSize(latex22->GetTextSize()*0.8);
  latex22->DrawLatex(0.12,0.39,"Q^{2}_{s,GBW}(x,^{197}Au)");

  TLatex* latex_new = new TLatex();
  latex_new->SetNDC();
  latex_new->SetTextFont(42);
  latex_new->SetTextColor(1);
  latex_new->SetTextSize(latex_new->GetTextSize()*0.7);
  latex_new->DrawLatex(0.13,0.23,"perturbative");
  latex_new->DrawLatex(0.13,0.18,"non-perturbative");

  TF1* func_acc[10];
  TF1* func1_acc[10];
  TF1* func2_acc[10];
  TF1* func3_acc[10];

  TF1* func_energy[12];
  TF1* func1_energy[12];
  TF1* func2_energy[12];
  TF1* func3_energy[12];

  for(int i=0;i<10;i++)
  {
    func_acc[i] = new TF1(Form("func_acc_%d",i),"x*(pow([0]+[1],2)-pow([0]-[1],2))/(1+x*[0]*exp(-2*[2])/[1])",0.0000001,1);
    func_acc[i]->SetParameters(beam_ion,beam_muon_max,-7+i);
    func_acc[i]->SetLineColor(1);
    func_acc[i]->SetLineStyle(7);

    func1_acc[i] = new TF1(Form("func1_acc_%d",i),"x*(pow([0]+[1],2)-pow([0]-[1],2))/(1+[1]*exp(2*[2])/x/[0])",0.0000001,1);
    func1_acc[i]->SetParameters(beam_ion,beam_muon_max,3-i);
    func1_acc[i]->SetLineColor(1);
    func1_acc[i]->SetLineStyle(7);

    func2_acc[i] = new TF1(Form("func2_acc_%d",i),"x*(pow([0]+[1],2)-pow([0]-[1],2))/(1+x*[0]*exp(-2*[2])/[1])",0.0000001,1);
    func2_acc[i]->SetParameters(2750.,50.,-7+i);
    func2_acc[i]->SetLineColor(1);
    func2_acc[i]->SetLineStyle(7);

    func3_acc[i] = new TF1(Form("func3_acc_%d",i),"x*(pow([0]+[1],2)-pow([0]-[1],2))/(1+[1]*exp(2*[2])/x/[0])",0.0000001,1);
    func3_acc[i]->SetParameters(2750.,50.,5-i);
    func3_acc[i]->SetLineColor(1);
    func3_acc[i]->SetLineStyle(7);
  }

  double haden_muic[] = {300,80,20,10,5,1};
  double lepen_muic[] = {930,600,400,50,10,5};
  double haden_lhec[] = {1200,400,120,30,12,4};
  double lepen_lhec[] = {48,35,10,5,60,120};

  for(int i=0;i<6;i++)
  {
// muic
    func_energy[i] = new TF1(Form("func_energy_%d",i),"(1-[2]/[1])/(1/(x*(pow([0]+[1],2)-pow([0]-[1],2)))-1/(4*[1]*[1]))",0.0000001,1);
    func_energy[i]->SetParameters(beam_ion,beam_muon_max,lepen_muic[i]);
    func_energy[i]->SetLineColor(1);
    func_energy[i]->SetLineStyle(10);

    func1_energy[i] = new TF1(Form("func1_energy_%d",i),"x*(pow([0]+[1],2)-pow([0]-[1],2))*(1-[2]/(x*[0]))/(1-[1]/(x*[0]))",0.0000001,1);
    func1_energy[i]->SetParameters(beam_ion,beam_muon_max,haden_muic[i]);
    func1_energy[i]->SetLineColor(1);
    func1_energy[i]->SetLineStyle(10);

// lhec
    if(lepen_lhec[i]<50) func2_energy[i] = new TF1(Form("func2_energy_%d",i),"(1-[2]/[1])/(1/(x*(pow([0]+[1],2)-pow([0]-[1],2)))-1/(4.*[1]*[1]))",0.0000001,4.*50*50./(pow(50+2750.,2)-pow(2750.-50,2))/0.95*(0.95+lepen_lhec[i]/50.-1));
    else func2_energy[i] = new TF1(Form("func2_energy_%d",i),"(1-[2]/[1])/(1/(x*(pow([0]+[1],2)-pow([0]-[1],2)))-1/(4.*[1]*[1]))",4.*50*50./(pow(50+2750.,2)-pow(2750.-50,2))/0.95*(0.95+lepen_lhec[i]/50.-1),1);
    func2_energy[i]->SetParameters(2750.,50.,lepen_lhec[i]);
    func2_energy[i]->SetLineColor(1);
    func2_energy[i]->SetLineStyle(10);

    if(haden_lhec[i]>50.) func3_energy[i] = new TF1(Form("func3_energy_%d",i),"x*(pow([0]+[1],2)-pow([0]-[1],2))*(1-[2]/(x*[0]))/(1-[1]/(x*[0]))",50./2750,1);
    else func3_energy[i] = new TF1(Form("func3_energy_%d",i),"x*(pow([0]+[1],2)-pow([0]-[1],2))*(1-[2]/(x*[0]))/(1-[1]/(x*[0]))",0.0000001,50./2750);
    func3_energy[i]->SetParameters(2750.,50.,haden_lhec[i]);
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
  func_acc[1]->Draw("Lsame");
  func_acc[2]->Draw("Lsame");
  func_acc[3]->Draw("Lsame");
  func_acc[4]->Draw("Lsame");
  func_acc[5]->Draw("Lsame");
  func_acc[6]->Draw("Lsame");

  func_energy[0]->Draw("Lsame");
  func_energy[1]->Draw("Lsame");

  sat_A->Draw("Lsame");
  latex22->DrawLatex(0.12,0.39,"Q^{2}_{s,GBW}(x,^{197}Au)");
  latex2->DrawLatex(0.15,0.6,"0.01 < y < 0.95");

  TLegend* legend1 = new TLegend(0.12,0.78,0.6,0.88);
  legend1->SetFillColor(0);
  legend1->SetBorderSize(0);
  legend1->AddEntry(gr_muic1,Form("MuIC: #mu^{-} (%.0f) + A (%.0f)",beam_muon_max,beam_ion),"F");
  legend1->Draw("");

  TLatex* latex = new TLatex();
  latex->SetNDC();
  latex->SetTextFont(42);
  latex->SetTextSize(latex->GetTextSize()*0.9);
  latex->DrawLatex(0.15,0.6,"0.01 < y < 0.95");
  latex->SetTextColor(1);
  latex->SetTextSize(latex->GetTextSize()*0.9);
  latex->DrawLatex(0.91,0.26,"#eta_{#mu} = -7");
  latex->DrawLatex(0.91,0.36,"#eta_{#mu} = -6");
  latex->DrawLatex(0.91,0.46,"#eta_{#mu} = -5");
  latex->DrawLatex(0.91,0.56,"#eta_{#mu} = -4");
  latex->DrawLatex(0.91,0.66,"#eta_{#mu} = -3");
  latex->DrawLatex(0.91,0.76,"#eta_{#mu} = -2");
  latex->DrawLatex(0.91,0.83,"#eta_{#mu} = -1");

  TLatex* latex5a = new TLatex();
  latex5a->SetNDC();
  latex5a->SetTextFont(42);
//  latex5a->SetTextColor(kRed);
  latex5a->SetTextSize(latex5a->GetTextSize()*0.7);
  latex5a->SetTextAngle(35);
  latex5a->DrawLatex(0.645,0.47,"E^{f}_{#mu} = 930");
  latex5a->DrawLatex(0.6,0.55,"E^{f}_{#mu} = 600");

  TCanvas* c1a = new TCanvas("c1a","",700,500);
  c1a->SetLogy();
  c1a->SetLogx();
  c1a->SetTopMargin(0.06);
  c1a->SetBottomMargin(0.105);
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

  sat_A->Draw("Lsame");
  latex22->DrawLatex(0.12,0.39,"Q^{2}_{s,GBW}(x,^{197}Au)");
  latex2->DrawLatex(0.15,0.6,"0.01 < y < 0.95");

  legend1->Draw("");

  TLatex* latex3 = new TLatex();
  latex3->SetNDC();
  latex3->SetTextFont(42);
  latex3->SetTextColor(1);
  latex3->SetTextSize(latex3->GetTextSize()*0.8);
  latex3->SetTextAngle(50);
  latex3->DrawLatex(0.2,0.12,"#eta_{h} = -6");
  latex3->DrawLatex(0.31,0.12,"#eta_{h} = -4");
  latex3->DrawLatex(0.42,0.12,"#eta_{h} = -2");
  latex3->DrawLatex(0.53,0.12,"#eta_{h} = 0");
  latex3->DrawLatex(0.64,0.12,"#eta_{h} = 2");

  TLatex* latex7b = new TLatex();
  latex7b->SetNDC();
  latex7b->SetTextFont(42);
  latex7b->SetTextColor(1);
  latex7b->SetTextSize(latex7b->GetTextSize()*0.7);
  latex7b->SetTextAngle(90);
  latex7b->DrawLatex(0.87,0.23,"E^{f}_{h} = 80");
  latex7b->DrawLatex(0.79,0.23,"E^{f}_{h} = 20");
  latex7b->DrawLatex(0.71,0.23,"E^{f}_{h} = 5");
  latex7b->SetTextAngle(35);
  latex7b->DrawLatex(0.67,0.61,"E^{f}_{h} = 300");

  TCanvas* c2 = new TCanvas("c2","",700,500);
  c2->SetLogy();
  c2->SetLogx();
  c2->SetTopMargin(0.06);
  c2->SetBottomMargin(0.105);
  htmp->Draw();
  gr_lhec1->Draw("LFsame");
  line->Draw("Lsame");
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

  sat_A->Draw("Lsame");
  latex22->DrawLatex(0.12,0.39,"Q^{2}_{s,GBW}(x,^{197}Au)");
  latex2->DrawLatex(0.15,0.6,"0.01 < y < 0.95");

  TLegend* legend2 = new TLegend(0.12,0.78,0.6,0.88);
  legend2->SetFillColor(0);
  legend2->SetBorderSize(0);
  legend2->AddEntry(gr_lhec1,"LHeC: #it{e}^{-} (50) + A (2750)","F");
  legend2->Draw("");

  TLatex* latex4 = new TLatex();
  latex4->SetNDC();
  latex4->SetTextFont(42);
  latex4->SetTextSize(latex4->GetTextSize()*0.9);
  latex4->DrawLatex(0.15,0.6,"0.01 < y < 0.95");
  latex4->SetTextColor(1);
  latex4->SetTextSize(latex4->GetTextSize()*0.9);
  latex4->DrawLatex(0.91,0.27,"#eta_{e} = -4");
  latex4->DrawLatex(0.91,0.37,"#eta_{e} = -3");
  latex4->DrawLatex(0.91,0.47,"#eta_{e} = -2");
  latex4->DrawLatex(0.91,0.575,"#eta_{e} = -1");
  latex4->DrawLatex(0.91,0.67,"#eta_{e} = 0");
  latex4->DrawLatex(0.91,0.77,"#eta_{e} = 1");
  latex4->DrawLatex(0.91,0.84,"#eta_{e} = 2");

  TLatex* latex8a = new TLatex();
  latex8a->SetNDC();
  latex8a->SetTextFont(42);
  latex8a->SetTextColor(1);
  latex8a->SetTextSize(latex8a->GetTextSize()*0.7);
  latex8a->SetTextAngle(35);
  latex8a->DrawLatex(0.43,0.3,"E^{f}_{e} = 48");
  latex8a->DrawLatex(0.39,0.36,"E^{f}_{e} = 35");
  latex8a->SetTextAngle(0);
  latex8a->DrawLatex(0.75,0.62,"E^{f}_{e} = 60");
  latex8a->DrawLatex(0.78,0.71,"E^{f}_{e} = 120");

  TCanvas* c2a = new TCanvas("c2a","",700,500);
  c2a->SetLogy();
  c2a->SetLogx();
  c2a->SetTopMargin(0.06);
  c2a->SetBottomMargin(0.105);
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

  sat_A->Draw("Lsame");
  latex22->DrawLatex(0.12,0.39,"Q^{2}_{s,GBW}(x,^{197}Au)");
  latex2->DrawLatex(0.15,0.6,"0.01 < y < 0.95");

  legend2->Draw("");

  TLatex* latex5 = new TLatex();
  latex5->SetNDC();
  latex5->SetTextFont(42);
  latex5->SetTextColor(1);
  latex5->SetTextSize(latex5->GetTextSize()*0.8);
  latex5->SetTextAngle(50);
  latex5->DrawLatex(0.14,0.12,"#eta_{h} = -4");
  latex5->DrawLatex(0.24,0.12,"#eta_{h} = -2");
  latex5->DrawLatex(0.35,0.12,"#eta_{h} = 0");
  latex5->DrawLatex(0.46,0.12,"#eta_{h} = 2");
  latex5->DrawLatex(0.57,0.12,"#eta_{h} = 4");

  TLatex* latex10b = new TLatex();
  latex10b->SetNDC();
  latex10b->SetTextFont(42);
  latex10b->SetTextColor(1);
  latex10b->SetTextSize(latex10b->GetTextSize()*0.7);
  latex10b->SetTextAngle(90);
  latex10b->DrawLatex(0.84,0.23,"E^{f}_{h} = 1200");
  latex10b->DrawLatex(0.78,0.23,"E^{f}_{h} = 400");
  latex10b->DrawLatex(0.715,0.23,"E^{f}_{h} = 120");
  latex10b->DrawLatex(0.635,0.23,"E^{f}_{h} = 30");
  latex10b->DrawLatex(0.585,0.23,"E^{f}_{h} = 12");
  latex10b->DrawLatex(0.525,0.23,"E^{f}_{h} = 4");

  c->Print(Form("Q2vsx_allcolliders_eA_mu%.0f.pdf",beam_muon_max));
  c->Print(Form("Q2vsx_allcolliders_eA_mu%.0f.png",beam_muon_max));
  c1->Print(Form("Q2vsx_muic_eA_e_mu%.0f.pdf",beam_muon_max));
  c1->Print(Form("Q2vsx_muic_eA_e_mu%.0f.png",beam_muon_max));
  c1a->Print(Form("Q2vsx_muic_eA_h_mu%.0f.pdf",beam_muon_max));
  c1a->Print(Form("Q2vsx_muic_eA_h_mu%.0f.png",beam_muon_max));
  c2->Print("Q2vsx_lhec_eA_e.pdf");
  c2->Print("Q2vsx_lhec_eA_e.png");
  c2a->Print("Q2vsx_lhec_eA_h.pdf");
  c2a->Print("Q2vsx_lhec_eA_h.png");
}

