(* ::Package:: *)

SS[r1_,l1_,r2_,l2_,q_,t_]:=
Module[{ft1,ft2,f\[Theta]1,f\[Theta]2,solt,q0,q1,q2,q3,tx,ty,tz,t1,t2,\[Theta]1,\[Theta]2,d,ret,mind,mini,solk1,ar3,ar,k1,nsolutions,ii,restol1,realsolns,tmp,p1,p2,sol\[Theta]1,sol\[Theta]2,sol\[Theta]12,sol\[Theta]22,sol\[Theta]21,sol\[Theta]11,polyk1},
Print["We are in SS now"];
{q0,q1,q2,q3}=q;
{tx,ty,tz}=t;
p1={r1 Cos[\[Theta]1],r1 Sin[\[Theta]1],l1 t1};
p2={l2 (2 q0 q2+2 q1 q3) t2+tx+(q0^2+q1^2-q2^2-q3^2) r2 Cos[\[Theta]2]+(2 q1 q2-2 q0 q3) r2 Sin[\[Theta]2],l2 (-2 q0 q1+2 q2 q3) t2+ty+(2 q1 q2+2 q0 q3) r2 Cos[\[Theta]2]+(q0^2-q1^2+q2^2-q3^2) r2 Sin[\[Theta]2],l2 (q0^2-q1^2-q2^2+q3^2) t2+tz+(-2 q0 q2+2 q1 q3) r2 Cos[\[Theta]2]+(2 q0 q1+2 q2 q3) r2 Sin[\[Theta]2]};

d=Norm[p1-p2];


solt=sssoltf[\[Theta]1,\[Theta]2,t1,t2,r1,l1,r2,l2,q,t];
{sol\[Theta]1,sol\[Theta]11,sol\[Theta]12,sol\[Theta]2,sol\[Theta]21,sol\[Theta]22}=sssol\[Theta]f[\[Theta]1,\[Theta]2,t1,t2,r1,l1,r2,l2,q,t];
nsolutions={Flatten[{sol\[Theta]1[[1]],sol\[Theta]21[[1]]}],Flatten[{sol\[Theta]1[[1]],sol\[Theta]21[[2]]}],Flatten[{sol\[Theta]1[[2]],sol\[Theta]22[[1]]}],Flatten[{sol\[Theta]1[[2]],sol\[Theta]22[[2]]}],Flatten[{sol\[Theta]11[[1]],sol\[Theta]2[[1]]}],Flatten[{sol\[Theta]11[[2]],sol\[Theta]2[[1]]}],Flatten[{sol\[Theta]12[[1]],sol\[Theta]2[[2]]}],Flatten[{sol\[Theta]12[[2]],sol\[Theta]2[[2]] }],Flatten[{sol\[Theta]1[[1]],sol\[Theta]2[[1]]} ],Flatten[{sol\[Theta]1[[1]],sol\[Theta]2[[2]]} ],Flatten[{sol\[Theta]1[[2]],sol\[Theta]2[[2]]} ],Flatten[{sol\[Theta]1[[2]],sol\[Theta]2[[1]]} ]};
For[ii=1,ii<= Length[nsolutions],ii++,
nsolutions[[ii]]=Append[nsolutions[[ii]],solt /.nsolutions[[ii]]];
nsolutions[[ii]]=Flatten[nsolutions[[ii]]];
];


(*filtering out real solutions*)

restol1=10^-3;
realsolns={};
For[ii=1,ii<= Length[nsolutions],ii++,
tmp={\[Theta]1,\[Theta]2,t1,t2}/.nsolutions[[ii]];
If[Abs[Im[tmp]][[1]]<=  restol1 && Abs[Im[tmp]][[2]]<= restol1 && Abs[Im[tmp]][[3]]<= restol1 && Abs[Im[tmp]][[4]]<= restol1,realsolns=Append[realsolns,nsolutions[[ii]]]]
];

mind=d/.realsolns[[1]];
mini=1;
Print["t1=",t1/.realsolns[[1]],"    ","t2=",t2/.realsolns[[1]],"     ","d=",d/.realsolns[[1]],"\[Theta]1=",\[Theta]1/.realsolns[[1]],"\[Theta]2=",\[Theta]2/.realsolns[[1]]];
For[ii=2,ii<= Length[realsolns],ii++,
Print["t1=",t1/.realsolns[[ii]],"    ","t2=",t2/.realsolns[[ii]],"     ","d=",d/.realsolns[[ii]],"\[Theta]1=",\[Theta]1/.realsolns[[1]],"\[Theta]2=",\[Theta]2/.realsolns[[1]]];
If[(d/.realsolns[[ii]])<mind,mind=(d/.realsolns[[ii]]);mini=ii]
];
(*
Returns, p1, p2, min distance, {\[Theta]1,\[Theta]2,t1,t2}
*)
If[(t1/.realsolns[[mini]])<= 0,ft1=0;,If[(t1/.realsolns[[mini]])>= 1,ft1=1;,ft1=(t1/.realsolns[[mini]])]];
If[(t2/.realsolns[[mini]])<= 0,ft2=0;,If[(t2/.realsolns[[mini]])>= 1,ft2=1;,ft2=(t2/.realsolns[[mini]])]];
f\[Theta]1=\[Theta]1/.realsolns[[mini]];
f\[Theta]2=\[Theta]2/.realsolns[[mini]];
ret={p1/.realsolns[[mini]],p2/.realsolns[[mini]],mind,{f\[Theta]1,f\[Theta]2,ft1,ft2}};
Return[ret];
]


sssoltf[\[Theta]1_,\[Theta]2_,t1_,t2_,r1_,l1_,r2_,l2_,q_,t_]:=
Module[{q0,q1,q2,q3,tx,ty,tz},
{q0,q1,q2,q3}=q;
{tx,ty,tz}=t;

Return[{t1->(-l2 (q0^2-q1^2-q2^2+q3^2) (2 (q0 q2 tx+q1 q3 tx-q0 q1 ty+q2 q3 ty)+(q0^2-q1^2-q2^2+q3^2) tz-2 (q0 q2+q1 q3) r1 Cos[\[Theta]1]+2 (q0 q1-q2 q3) r1 Sin[\[Theta]1])+l2 (q0^2+q1^2+q2^2+q3^2)^2 (tz+2 (-q0 q2+q1 q3) r2 Cos[\[Theta]2]+2 (q0 q1+q2 q3) r2 Sin[\[Theta]2]))/(4 l1 l2 (q1^2+q2^2) (q0^2+q3^2)),t2->(q0 (-q2 tx+q1 ty)-q3 (q1 tx+q2 ty)+(q0 q2+q1 q3) r1 Cos[\[Theta]1]+(-q0 q1+q2 q3) r1 Sin[\[Theta]1]+(q0^2-q1^2-q2^2+q3^2) r2 ((-q0 q2+q1 q3) Cos[\[Theta]2]+(q0 q1+q2 q3) Sin[\[Theta]2]))/(2 l2 (q1^2+q2^2) (q0^2+q3^2))}];
]


sssol\[Theta]f[\[Theta]1_,\[Theta]2_,t1_,t2_,r1_,l1_,r2_,l2_,q_,t_]:=
Module[{ret,q0,q1,q2,q3,tx,ty,tz,sol\[Theta]1,sol\[Theta]11,sol\[Theta]12,sol\[Theta]2,sol\[Theta]21,sol\[Theta]22},
{q0,q1,q2,q3}=q;
{tx,ty,tz}=t;
sol\[Theta]1={{\[Theta]1->\[Pi]/2+ArcTan[(q0 q2+q1 q3)/Sqrt[(q0 q2+q1 q3)^2+(-q0 q1+q2 q3)^2],(-q0 q1+q2 q3)/Sqrt[(q0 q2+q1 q3)^2+(-q0 q1+q2 q3)^2]]},{\[Theta]1->-(\[Pi]/2)+ArcTan[(q0 q2+q1 q3)/Sqrt[(q0 q2+q1 q3)^2+(-q0 q1+q2 q3)^2],(-q0 q1+q2 q3)/Sqrt[(q0 q2+q1 q3)^2+(-q0 q1+q2 q3)^2]]}};
sol\[Theta]21={{\[Theta]2->ArcCos[(q0^2 (q1^2+q2^2) r1-q0 Sqrt[(q1^2+q2^2) (q0^2+q3^2)] (q1 tx+q2 ty)+q3 (q1^2 q3 r1+q2^2 q3 r1+q2 Sqrt[(q1^2+q2^2) (q0^2+q3^2)] tx-q1 Sqrt[(q1^2+q2^2) (q0^2+q3^2)] ty))/(Sqrt[(q1^2+q2^2) (q0^2+q3^2)] Sqrt[(q1^2+q2^2) (q0^2+q3^2) (q0^2+q1^2+q2^2+q3^2)^2 r2^2])]+ArcTan[((q0^3 q1+q0^2 q2 q3+q0 q1 (q1^2+q2^2+q3^2)+q2 q3 (q1^2+q2^2+q3^2)) r2)/Sqrt[(q1^2+q2^2) (q0^2+q3^2) (q0^2+q1^2+q2^2+q3^2)^2 r2^2],((q0^3 q2-q0^2 q1 q3+q0 q2 (q1^2+q2^2+q3^2)-q1 q3 (q1^2+q2^2+q3^2)) r2)/Sqrt[(q1^2+q2^2) (q0^2+q3^2) (q0^2+q1^2+q2^2+q3^2)^2 r2^2]]},{\[Theta]2->-ArcCos[(q0^2 (q1^2+q2^2) r1-q0 Sqrt[(q1^2+q2^2) (q0^2+q3^2)] (q1 tx+q2 ty)+q3 (q1^2 q3 r1+q2^2 q3 r1+q2 Sqrt[(q1^2+q2^2) (q0^2+q3^2)] tx-q1 Sqrt[(q1^2+q2^2) (q0^2+q3^2)] ty))/(Sqrt[(q1^2+q2^2) (q0^2+q3^2)] Sqrt[(q1^2+q2^2) (q0^2+q3^2) (q0^2+q1^2+q2^2+q3^2)^2 r2^2])]+ArcTan[((q0^3 q1+q0^2 q2 q3+q0 q1 (q1^2+q2^2+q3^2)+q2 q3 (q1^2+q2^2+q3^2)) r2)/Sqrt[(q1^2+q2^2) (q0^2+q3^2) (q0^2+q1^2+q2^2+q3^2)^2 r2^2],((q0^3 q2-q0^2 q1 q3+q0 q2 (q1^2+q2^2+q3^2)-q1 q3 (q1^2+q2^2+q3^2)) r2)/Sqrt[(q1^2+q2^2) (q0^2+q3^2) (q0^2+q1^2+q2^2+q3^2)^2 r2^2]]}};
sol\[Theta]22={{\[Theta]2->ArcCos[(-q0^2 (q1^2+q2^2) r1-q0 Sqrt[(q1^2+q2^2) (q0^2+q3^2)] (q1 tx+q2 ty)-q3 (q1^2 q3 r1+q2^2 q3 r1-q2 Sqrt[(q1^2+q2^2) (q0^2+q3^2)] tx+q1 Sqrt[(q1^2+q2^2) (q0^2+q3^2)] ty))/(Sqrt[(q1^2+q2^2) (q0^2+q3^2)] Sqrt[(q1^2+q2^2) (q0^2+q3^2) (q0^2+q1^2+q2^2+q3^2)^2 r2^2])]+ArcTan[((q0^3 q1+q0^2 q2 q3+q0 q1 (q1^2+q2^2+q3^2)+q2 q3 (q1^2+q2^2+q3^2)) r2)/Sqrt[(q1^2+q2^2) (q0^2+q3^2) (q0^2+q1^2+q2^2+q3^2)^2 r2^2],((q0^3 q2-q0^2 q1 q3+q0 q2 (q1^2+q2^2+q3^2)-q1 q3 (q1^2+q2^2+q3^2)) r2)/Sqrt[(q1^2+q2^2) (q0^2+q3^2) (q0^2+q1^2+q2^2+q3^2)^2 r2^2]]},{\[Theta]2->-ArcCos[(-q0^2 (q1^2+q2^2) r1-q0 Sqrt[(q1^2+q2^2) (q0^2+q3^2)] (q1 tx+q2 ty)-q3 (q1^2 q3 r1+q2^2 q3 r1-q2 Sqrt[(q1^2+q2^2) (q0^2+q3^2)] tx+q1 Sqrt[(q1^2+q2^2) (q0^2+q3^2)] ty))/(Sqrt[(q1^2+q2^2) (q0^2+q3^2)] Sqrt[(q1^2+q2^2) (q0^2+q3^2) (q0^2+q1^2+q2^2+q3^2)^2 r2^2])]+ArcTan[((q0^3 q1+q0^2 q2 q3+q0 q1 (q1^2+q2^2+q3^2)+q2 q3 (q1^2+q2^2+q3^2)) r2)/Sqrt[(q1^2+q2^2) (q0^2+q3^2) (q0^2+q1^2+q2^2+q3^2)^2 r2^2],((q0^3 q2-q0^2 q1 q3+q0 q2 (q1^2+q2^2+q3^2)-q1 q3 (q1^2+q2^2+q3^2)) r2)/Sqrt[(q1^2+q2^2) (q0^2+q3^2) (q0^2+q1^2+q2^2+q3^2)^2 r2^2]]}};
sol\[Theta]2={{\[Theta]2->\[Pi]/2+ArcTan[(q0 q2-q1 q3)/Sqrt[(q0 q2-q1 q3)^2+(-q0 q1-q2 q3)^2],(-q0 q1-q2 q3)/Sqrt[(q0 q2-q1 q3)^2+(-q0 q1-q2 q3)^2]]},{\[Theta]2->-(\[Pi]/2)+ArcTan[(q0 q2-q1 q3)/Sqrt[(q0 q2-q1 q3)^2+(-q0 q1-q2 q3)^2],(-q0 q1-q2 q3)/Sqrt[(q0 q2-q1 q3)^2+(-q0 q1-q2 q3)^2]]}};
sol\[Theta]11={{\[Theta]1->ArcCos[-(q0^4 (q1^2+q2^2) r2+q0^2 (q1^2+q2^2) (q1^2+q2^2+2 q3^2) r2+q0 Sqrt[(q1^2+q2^2) (q0^2+q3^2)] (q1 tx+q2 ty)+q3 (q1^4 q3 r2+q1^2 q3 (2 q2^2+q3^2) r2+q2 (q2^3 q3 r2+q2 q3^3 r2-Sqrt[(q1^2+q2^2) (q0^2+q3^2)] tx)+q1 Sqrt[(q1^2+q2^2) (q0^2+q3^2)] ty))/(Sqrt[(q1^2+q2^2) (q0^2+q3^2)] Sqrt[(-q0 q2 r1-q1 q3 r1)^2+(-q0 q1 r1+q2 q3 r1)^2])]+ArcTan[(-q0 q1 r1+q2 q3 r1)/Sqrt[(-q0 q2 r1-q1 q3 r1)^2+(-q0 q1 r1+q2 q3 r1)^2],(-q0 q2 r1-q1 q3 r1)/Sqrt[(-q0 q2 r1-q1 q3 r1)^2+(-q0 q1 r1+q2 q3 r1)^2]]},{\[Theta]1->-ArcCos[-(q0^4 (q1^2+q2^2) r2+q0^2 (q1^2+q2^2) (q1^2+q2^2+2 q3^2) r2+q0 Sqrt[(q1^2+q2^2) (q0^2+q3^2)] (q1 tx+q2 ty)+q3 (q1^4 q3 r2+q1^2 q3 (2 q2^2+q3^2) r2+q2 (q2^3 q3 r2+q2 q3^3 r2-Sqrt[(q1^2+q2^2) (q0^2+q3^2)] tx)+q1 Sqrt[(q1^2+q2^2) (q0^2+q3^2)] ty))/(Sqrt[(q1^2+q2^2) (q0^2+q3^2)] Sqrt[(-q0 q2 r1-q1 q3 r1)^2+(-q0 q1 r1+q2 q3 r1)^2])]+ArcTan[(-q0 q1 r1+q2 q3 r1)/Sqrt[(-q0 q2 r1-q1 q3 r1)^2+(-q0 q1 r1+q2 q3 r1)^2],(-q0 q2 r1-q1 q3 r1)/Sqrt[(-q0 q2 r1-q1 q3 r1)^2+(-q0 q1 r1+q2 q3 r1)^2]]}};
sol\[Theta]12={{\[Theta]1->ArcCos[-(-q0^4 (q1^2+q2^2) r2-q0^2 (q1^2+q2^2) (q1^2+q2^2+2 q3^2) r2+q0 Sqrt[(q1^2+q2^2) (q0^2+q3^2)] (q1 tx+q2 ty)-q3 (q1^4 q3 r2+q1^2 q3 (2 q2^2+q3^2) r2+q2 (q2^3 q3 r2+q2 q3^3 r2+Sqrt[(q1^2+q2^2) (q0^2+q3^2)] tx)-q1 Sqrt[(q1^2+q2^2) (q0^2+q3^2)] ty))/(Sqrt[(q1^2+q2^2) (q0^2+q3^2)] Sqrt[(-q0 q2 r1-q1 q3 r1)^2+(-q0 q1 r1+q2 q3 r1)^2])]+ArcTan[(-q0 q1 r1+q2 q3 r1)/Sqrt[(-q0 q2 r1-q1 q3 r1)^2+(-q0 q1 r1+q2 q3 r1)^2],(-q0 q2 r1-q1 q3 r1)/Sqrt[(-q0 q2 r1-q1 q3 r1)^2+(-q0 q1 r1+q2 q3 r1)^2]]},{\[Theta]1->-ArcCos[-(-q0^4 (q1^2+q2^2) r2-q0^2 (q1^2+q2^2) (q1^2+q2^2+2 q3^2) r2+q0 Sqrt[(q1^2+q2^2) (q0^2+q3^2)] (q1 tx+q2 ty)-q3 (q1^4 q3 r2+q1^2 q3 (2 q2^2+q3^2) r2+q2 (q2^3 q3 r2+q2 q3^3 r2+Sqrt[(q1^2+q2^2) (q0^2+q3^2)] tx)-q1 Sqrt[(q1^2+q2^2) (q0^2+q3^2)] ty))/(Sqrt[(q1^2+q2^2) (q0^2+q3^2)] Sqrt[(-q0 q2 r1-q1 q3 r1)^2+(-q0 q1 r1+q2 q3 r1)^2])]+ArcTan[(-q0 q1 r1+q2 q3 r1)/Sqrt[(-q0 q2 r1-q1 q3 r1)^2+(-q0 q1 r1+q2 q3 r1)^2],(-q0 q2 r1-q1 q3 r1)/Sqrt[(-q0 q2 r1-q1 q3 r1)^2+(-q0 q1 r1+q2 q3 r1)^2]]}};
ret={sol\[Theta]1,sol\[Theta]11,sol\[Theta]12,sol\[Theta]2,sol\[Theta]21,sol\[Theta]22};
Return[ret];
]

