(* ::Package:: *)

DL[r1_,l1_,r2_,l2_,q_,t_]:=
Module[{ft1,ft2,f\[Theta]1,f\[Theta]2,q0,q1,q2,q3,tx,ty,tz,t1,t2,\[Theta]1,\[Theta]2,d,ret,mind,mini,solk1,ar3,ar,k1,nsolutions,ii,restol1,realsolns,tmp,p1,p2,sol\[Theta]1,sol\[Theta]2,sol\[Theta]12,sol\[Theta]22,sol\[Theta]21,sol\[Theta]11,solt2,solt1,polyk1,solt2s,solt1s,sol\[Theta]1s,sol\[Theta]2s},
Print["we are in DL now"];
{q0,q1,q2,q3}=q;
{tx,ty,tz}=t;
p1={r1*t1* Cos[\[Theta]1],r1 t1 Sin[\[Theta]1],0};
p2={l2 (2 q0 q2+2 q1 q3) t2+tx,l2 (-2 q0 q1+2 q2 q3) t2+ty,l2 (q0^2-q1^2-q2^2+q3^2) t2+tz};

d=Norm[p1-p2];


solt2=dlsolt2f[\[Theta]1,t1,t2,r1,l1,r2,l2,q,t];
solt1=dlsolt1f[\[Theta]1,t1,t2,r1,l1,r2,l2,q,t];
sol\[Theta]1=dlsol\[Theta]1f[\[Theta]1,t1,t2,r1,l1,r2,l2,q,t];
nsolutions=Array[0&,Length[sol\[Theta]1]];
For[ii=1,ii<=Length[sol\[Theta]1],ii++,
nsolutions[[ii]]=sol\[Theta]1[[ii]];
];


For[ii=1,ii<= Length[nsolutions],ii++,
nsolutions[[ii]]=Append[nsolutions[[ii]],solt1 /.nsolutions[[ii]]];
nsolutions[[ii]]=Append[nsolutions[[ii]],solt2/.nsolutions[[ii]]];
nsolutions[[ii]]=Flatten[nsolutions[[ii]]];
];


(*filtering out real solutions*)

restol1=10^-3;
realsolns={};
For[ii=1,ii<= Length[nsolutions],ii++,
tmp={\[Theta]1,t1,t2}/.nsolutions[[ii]];
If[Abs[Im[tmp]][[1]]<=  restol1  && Abs[Im[tmp]][[2]]<= restol1 && Abs[Im[tmp]][[3]]<= restol1,realsolns=Append[realsolns,nsolutions[[ii]]]]
];

mind=d/.realsolns[[1]];
mini=1;

Print["s1=",t1/.realsolns[[1]],"    ","t2=",t2/.realsolns[[1]],"     ","d=",d/.realsolns[[1]],"           ","\[Theta]1=",\[Theta]1/.realsolns[[1]]];
For[ii=2,ii<= Length[realsolns],ii++,
Print["s1=",t1/.realsolns[[ii]],"    ","t2=",t2/.realsolns[[ii]],"     ","d=",d/.realsolns[[ii]],"           ","\[Theta]1=",\[Theta]1/.realsolns[[1]]];
If[(d/.realsolns[[ii]])<mind,mind=(d/.realsolns[[ii]]);mini=ii]
];
If[(t1/.realsolns[[mini]])<= 0,ft1=0;,If[(t1/.realsolns[[mini]])>= 1,ft1=1;,ft1=(t1/.realsolns[[mini]])]];
If[(t2/.realsolns[[mini]])<= 0,ft2=0;,If[(t2/.realsolns[[mini]])>= 1,ft2=1;,ft2=(t2/.realsolns[[mini]])]];
f\[Theta]1=\[Theta]1/.realsolns[[mini]];
ret={p1/.realsolns[[mini]],p2/.realsolns[[mini]],mind,{f\[Theta]1,ft1,ft2}};

Return[ret];
]



dlsol\[Theta]1f[\[Theta]1_,t1_,t2_,r1_,l1_,r2_,l2_,q_,t_]:=
Module[{q0,q1,q2,q3,tx,ty,tz},
{q0,q1,q2,q3}=q;
{tx,ty,tz}=t;

Return[{{\[Theta]1->ArcTan[tx-4 q0^2 q1^2 tx-4 q0^2 q2^2 tx-4 q1^2 q3^2 tx-4 q2^2 q3^2 tx-2 q0^3 q2 tz+2 q0 q1^2 q2 tz+2 q0 q2^3 tz-2 q0^2 q1 q3 tz+2 q1^3 q3 tz+2 q1 q2^2 q3 tz-2 q0 q2 q3^2 tz-2 q1 q3^3 tz,ty-4 q0^2 q1^2 ty-4 q0^2 q2^2 ty-4 q1^2 q3^2 ty-4 q2^2 q3^2 ty+2 q0^3 q1 tz-2 q0 q1^3 tz-2 q0 q1 q2^2 tz-2 q0^2 q2 q3 tz+2 q1^2 q2 q3 tz+2 q2^3 q3 tz+2 q0 q1 q3^2 tz-2 q2 q3^3 tz]},{\[Theta]1->ArcTan[-tx+4 q0^2 q1^2 tx+4 q0^2 q2^2 tx+4 q1^2 q3^2 tx+4 q2^2 q3^2 tx+2 q0^3 q2 tz-2 q0 q1^2 q2 tz-2 q0 q2^3 tz+2 q0^2 q1 q3 tz-2 q1^3 q3 tz-2 q1 q2^2 q3 tz+2 q0 q2 q3^2 tz+2 q1 q3^3 tz,-ty+4 q0^2 q1^2 ty+4 q0^2 q2^2 ty+4 q1^2 q3^2 ty+4 q2^2 q3^2 ty-2 q0^3 q1 tz+2 q0 q1^3 tz+2 q0 q1 q2^2 tz+2 q0^2 q2 q3 tz-2 q1^2 q2 q3 tz-2 q2^3 q3 tz-2 q0 q1 q3^2 tz+2 q2 q3^3 tz]}}];
]


dlsolt1f[\[Theta]1_,t1_,t2_,r1_,l1_,r2_,l2_,q_,t_]:=
Module[{q0,q1,q2,q3,tx,ty,tz},
{q0,q1,q2,q3}=q;
{tx,ty,tz}=t;

Return[t1->-(-tx Cos[\[Theta]1]+4 q0^2 q2^2 tx Cos[\[Theta]1]+8 q0 q1 q2 q3 tx Cos[\[Theta]1]+4 q1^2 q3^2 tx Cos[\[Theta]1]-4 q0^2 q1 q2 ty Cos[\[Theta]1]-4 q0 q1^2 q3 ty Cos[\[Theta]1]+4 q0 q2^2 q3 ty Cos[\[Theta]1]+4 q1 q2 q3^2 ty Cos[\[Theta]1]+2 q0^3 q2 tz Cos[\[Theta]1]-2 q0 q1^2 q2 tz Cos[\[Theta]1]-2 q0 q2^3 tz Cos[\[Theta]1]+2 q0^2 q1 q3 tz Cos[\[Theta]1]-2 q1^3 q3 tz Cos[\[Theta]1]-2 q1 q2^2 q3 tz Cos[\[Theta]1]+2 q0 q2 q3^2 tz Cos[\[Theta]1]+2 q1 q3^3 tz Cos[\[Theta]1]-4 q0^2 q1 q2 tx Sin[\[Theta]1]-4 q0 q1^2 q3 tx Sin[\[Theta]1]+4 q0 q2^2 q3 tx Sin[\[Theta]1]+4 q1 q2 q3^2 tx Sin[\[Theta]1]-ty Sin[\[Theta]1]+4 q0^2 q1^2 ty Sin[\[Theta]1]-8 q0 q1 q2 q3 ty Sin[\[Theta]1]+4 q2^2 q3^2 ty Sin[\[Theta]1]-2 q0^3 q1 tz Sin[\[Theta]1]+2 q0 q1^3 tz Sin[\[Theta]1]+2 q0 q1 q2^2 tz Sin[\[Theta]1]+2 q0^2 q2 q3 tz Sin[\[Theta]1]-2 q1^2 q2 q3 tz Sin[\[Theta]1]-2 q2^3 q3 tz Sin[\[Theta]1]-2 q0 q1 q3^2 tz Sin[\[Theta]1]+2 q2 q3^3 tz Sin[\[Theta]1])/(r1 (1-2 q0^2 q1^2-2 q0^2 q2^2-2 q1^2 q3^2-2 q2^2 q3^2+2 q0^2 q1^2 Cos[\[Theta]1]^2-2 q0^2 q2^2 Cos[\[Theta]1]^2-8 q0 q1 q2 q3 Cos[\[Theta]1]^2-2 q1^2 q3^2 Cos[\[Theta]1]^2+2 q2^2 q3^2 Cos[\[Theta]1]^2+8 q0^2 q1 q2 Cos[\[Theta]1] Sin[\[Theta]1]+8 q0 q1^2 q3 Cos[\[Theta]1] Sin[\[Theta]1]-8 q0 q2^2 q3 Cos[\[Theta]1] Sin[\[Theta]1]-8 q1 q2 q3^2 Cos[\[Theta]1] Sin[\[Theta]1]-2 q0^2 q1^2 Sin[\[Theta]1]^2+2 q0^2 q2^2 Sin[\[Theta]1]^2+8 q0 q1 q2 q3 Sin[\[Theta]1]^2+2 q1^2 q3^2 Sin[\[Theta]1]^2-2 q2^2 q3^2 Sin[\[Theta]1]^2))];
]


dlsolt2f[\[Theta]1_,t1_,t2_,r1_,l1_,r2_,l2_,q_,t_]:=
Module[{q0,q1,q2,q3,tx,ty,tz},
{q0,q1,q2,q3}=q;
{tx,ty,tz}=t;

Return[t2->1/l2 (-2 q0 q2 tx-2 q1 q3 tx+2 q0 q1 ty-2 q2 q3 ty-q0^2 tz+q1^2 tz+q2^2 tz-q3^2 tz+2 q0 q2 r1 t1 Cos[\[Theta]1]+2 q1 q3 r1 t1 Cos[\[Theta]1]-2 q0 q1 r1 t1 Sin[\[Theta]1]+2 q2 q3 r1 t1 Sin[\[Theta]1])]
]
