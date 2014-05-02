(* ::Package:: *)

BeginPackage["ServiceLine`"]

ExponentialFit::usage = "ExponentialFit[data,label] returns a fit of exponential distribution overlaid to a histogram of the data using the given labels as x,y axes"



(* -------------------------------- Private -------------------------------- *)
Begin["`Private`"]

ExponentialFit[data_,label_]:=Module[{\[Lambda],fit},
fit = FindDistributionParameters[data,ExponentialDistribution[\[Lambda]]];
Show[{
Plot[
PDF[ExponentialDistribution[\[Lambda]/.fit],x]
,{x,0,100}
,PlotRange->All
,PlotStyle->{Red,Thick}
,PlotLabel->label[[1]]<>" Mean = " <>ToString[1/\[Lambda]/.fit]
,Frame->{True,True}
,FrameLabel->label
]

,

Histogram[data,Automatic,"PDF"]
}]
]

End[]
EndPackage[]
