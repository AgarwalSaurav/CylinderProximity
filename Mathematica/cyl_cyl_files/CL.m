(* ::Package:: *)

solvequartic[a_,k_]:=Module[{a0,a1,a2,a3,a4,ret,rt1,rt2,rt3,rt4},

{a0,a1,a2,a3,a4}=a;
rt1={k->-(1/(12 a4))(3 a3+Sqrt[3] a4 \[Sqrt](1/a4^2(3 a3^2-8 a2 a4+(4 2^(1/3) a4 (a2^2-3 a1 a3+12 a0 a4))/(2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)+2 2^(2/3) a4 (2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)))+Sqrt[6] a4 \[Sqrt](-1/a4^3(-3 a3^2 a4+8 a2 a4^2+(2 2^(1/3) a4^2 (a2^2-3 a1 a3+12 a0 a4))/(2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)+2^(2/3) a4^2 (2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)-(3 Sqrt[3] (a3^3-4 a2 a3 a4+8 a1 a4^2))/(\[Sqrt](1/a4^2(3 a3^2-8 a2 a4+(4 2^(1/3) a4 (a2^2-3 a1 a3+12 a0 a4))/(2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)+2 2^(2/3) a4 (2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)))))))};
rt2={k->1/(12 a4) (-3 a3-Sqrt[3] a4 \[Sqrt](1/a4^2(3 a3^2-8 a2 a4+(4 2^(1/3) a4 (a2^2-3 a1 a3+12 a0 a4))/(2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)+2 2^(2/3) a4 (2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)))+Sqrt[6] a4 \[Sqrt](-1/a4^3(-3 a3^2 a4+8 a2 a4^2+(2 2^(1/3) a4^2 (a2^2-3 a1 a3+12 a0 a4))/(2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)+2^(2/3) a4^2 (2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)-(3 Sqrt[3] (a3^3-4 a2 a3 a4+8 a1 a4^2))/(\[Sqrt](1/a4^2(3 a3^2-8 a2 a4+(4 2^(1/3) a4 (a2^2-3 a1 a3+12 a0 a4))/(2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)+2 2^(2/3) a4 (2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)))))))};
rt3={k->1/(12 a4) (-3 a3+Sqrt[3] a4 \[Sqrt](1/a4^2(3 a3^2-8 a2 a4+(4 2^(1/3) a4 (a2^2-3 a1 a3+12 a0 a4))/(2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)+2 2^(2/3) a4 (2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)))-Sqrt[6] a4 \[Sqrt](-1/a4^3(-3 a3^2 a4+8 a2 a4^2+(2 2^(1/3) a4^2 (a2^2-3 a1 a3+12 a0 a4))/(2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)+2^(2/3) a4^2 (2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)+(3 Sqrt[3] (a3^3-4 a2 a3 a4+8 a1 a4^2))/(\[Sqrt](1/a4^2(3 a3^2-8 a2 a4+(4 2^(1/3) a4 (a2^2-3 a1 a3+12 a0 a4))/(2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)+2 2^(2/3) a4 (2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)))))))};
rt4={k->1/(12 a4) (-3 a3+Sqrt[3] a4 \[Sqrt](1/a4^2(3 a3^2-8 a2 a4+(4 2^(1/3) a4 (a2^2-3 a1 a3+12 a0 a4))/(2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)+2 2^(2/3) a4 (2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)))+Sqrt[6] a4 \[Sqrt](-1/a4^3(-3 a3^2 a4+8 a2 a4^2+(2 2^(1/3) a4^2 (a2^2-3 a1 a3+12 a0 a4))/(2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)+2^(2/3) a4^2 (2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)+(3 Sqrt[3] (a3^3-4 a2 a3 a4+8 a1 a4^2))/(\[Sqrt](1/a4^2(3 a3^2-8 a2 a4+(4 2^(1/3) a4 (a2^2-3 a1 a3+12 a0 a4))/(2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)+2 2^(2/3) a4 (2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)))))))};

Return[{rt1,rt2,rt3,rt4}];
]


CL[r1_,l1_,r2_,l2_,q_,t_]:=
Module[{ft1,ft2,f\[Theta]1,f\[Theta]2,q0,q1,q2,q3,tx,ty,tz,t1,t2,\[Theta]1,\[Theta]2,d,ret,mind,mini,solk1,ar3,ar,k1,nsolutions,ii,restol1,realsolns,tmp,p1,p2,sol\[Theta]1,sol\[Theta]2,sol\[Theta]12,sol\[Theta]22,sol\[Theta]21,sol\[Theta]11,solt2,solt1,polyk1,solt2s,solt1s,sol\[Theta]1s,sol\[Theta]2s},

{q0,q1,q2,q3}=q;
{tx,ty,tz}=t;
p1={r1 Cos[\[Theta]1],r1 Sin[\[Theta]1],0};
p2={l2 (2 q0 q2+2 q1 q3) t2+tx,l2 (-2 q0 q1+2 q2 q3) t2+ty,l2 (q0^2-q1^2-q2^2+q3^2) t2+tz};

d=Norm[p1-p2];

Print["we are in CL now"];
solt2=clsolt2f[\[Theta]1,t2,r1,l1,r2,l2,q,t];
solk1=clsolk1f[k1,r1,l1,r2,l2,q,t];

sol\[Theta]1={\[Theta]1->2*ArcTan[k1]}/.solk1;

nsolutions=Array[0&,Length[sol\[Theta]1]];
For[ii=1,ii<=Length[sol\[Theta]1],ii++,
nsolutions[[ii]]=sol\[Theta]1[[ii]];
];


For[ii=1,ii<= Length[nsolutions],ii++,
nsolutions[[ii]]=Append[nsolutions[[ii]],solt2/.nsolutions[[ii]]];
nsolutions[[ii]]=Flatten[nsolutions[[ii]]];
];


(*filtering out real solutions*)

restol1=10^-5;
realsolns={};
For[ii=1,ii<= Length[nsolutions],ii++,
tmp={\[Theta]1,t2}/.nsolutions[[ii]];
If[Abs[Im[tmp]][[1]]<=  restol1  && Abs[Im[tmp]][[2]]<= restol1,realsolns=Append[realsolns,nsolutions[[ii]]]]
];


mind=d/.realsolns[[1]];
mini=1;
Print["t2=",t2/.realsolns[[1]],"\[Theta]1=",\[Theta]1/.realsolns[[1]]];
For[ii=2,ii<= Length[realsolns],ii++,
Print["t2=",t2/.realsolns[[ii]],"\[Theta]1=",\[Theta]1/.realsolns[[ii]]];
If[(d/.realsolns[[ii]])<mind,mind=(d/.realsolns[[ii]]);mini=ii]
];

If[(t2/.realsolns[[mini]])<= 0,ft2=0;,If[(t2/.realsolns[[mini]])>= 1,ft2=1;,ft2=(t2/.realsolns[[mini]])]];
f\[Theta]1=\[Theta]1/.realsolns[[mini]];


ret={p1/.realsolns[[mini]],p2/.realsolns[[mini]],mind,{f\[Theta]1,ft2}};
Print[ret];
Return[ret];
]



clsolt2f[\[Theta]1_,t2_,r1_,l1_,r2_,l2_,q_,t_]:=
Module[{q0,q1,q2,q3,tx,ty,tz},
{q0,q1,q2,q3}=q;
{tx,ty,tz}=t;

Return[t2->1/l2 (-2 q0 q2 tx-2 q1 q3 tx+2 q0 q1 ty-2 q2 q3 ty-q0^2 tz+q1^2 tz+q2^2 tz-q3^2 tz+2 (q0 q2+q1 q3) r1 Cos[\[Theta]1]-2 (q0 q1-q2 q3) r1 Sin[\[Theta]1])];
]


clsolk1f[k1_,r1_,l1_,r2_,l2_,q_,t_]:=
Module[{a,solk1,q0,q1,q2,q3,tx,ty,tz},
{q0,q1,q2,q3}=q;
{tx,ty,tz}=t;

a={-4 q0^2 q1 q2 r1-4 q0 q1^2 q3 r1+4 q0 q2^2 q3 r1+4 q1 q2 q3^2 r1+4 q0^2 q1 q2 tx+4 q0 q1^2 q3 tx-4 q0 q2^2 q3 tx-4 q1 q2 q3^2 tx+ty-4 q0^2 q1^2 ty+8 q0 q1 q2 q3 ty-4 q2^2 q3^2 ty+2 q0^3 q1 tz-2 q0 q1^3 tz-2 q0 q1 q2^2 tz-2 q0^2 q2 q3 tz+2 q1^2 q2 q3 tz+2 q2^3 q3 tz+2 q0 q1 q3^2 tz-2 q2 q3^3 tz,8 q0^2 q1^2 r1-8 q0^2 q2^2 r1-32 q0 q1 q2 q3 r1-8 q1^2 q3^2 r1+8 q2^2 q3^2 r1-2 tx+8 q0^2 q2^2 tx+16 q0 q1 q2 q3 tx+8 q1^2 q3^2 tx-8 q0^2 q1 q2 ty-8 q0 q1^2 q3 ty+8 q0 q2^2 q3 ty+8 q1 q2 q3^2 ty+4 q0^3 q2 tz-4 q0 q1^2 q2 tz-4 q0 q2^3 tz+4 q0^2 q1 q3 tz-4 q1^3 q3 tz-4 q1 q2^2 q3 tz+4 q0 q2 q3^2 tz+4 q1 q3^3 tz,24 q0^2 q1 q2 r1+24 q0 q1^2 q3 r1-24 q0 q2^2 q3 r1-24 q1 q2 q3^2 r1,-8 q0^2 q1^2 r1+8 q0^2 q2^2 r1+32 q0 q1 q2 q3 r1+8 q1^2 q3^2 r1-8 q2^2 q3^2 r1-2 tx+8 q0^2 q2^2 tx+16 q0 q1 q2 q3 tx+8 q1^2 q3^2 tx-8 q0^2 q1 q2 ty-8 q0 q1^2 q3 ty+8 q0 q2^2 q3 ty+8 q1 q2 q3^2 ty+4 q0^3 q2 tz-4 q0 q1^2 q2 tz-4 q0 q2^3 tz+4 q0^2 q1 q3 tz-4 q1^3 q3 tz-4 q1 q2^2 q3 tz+4 q0 q2 q3^2 tz+4 q1 q3^3 tz,-4 q0^2 q1 q2 r1-4 q0 q1^2 q3 r1+4 q0 q2^2 q3 r1+4 q1 q2 q3^2 r1-4 q0^2 q1 q2 tx-4 q0 q1^2 q3 tx+4 q0 q2^2 q3 tx+4 q1 q2 q3^2 tx-ty+4 q0^2 q1^2 ty-8 q0 q1 q2 q3 ty+4 q2^2 q3^2 ty-2 q0^3 q1 tz+2 q0 q1^3 tz+2 q0 q1 q2^2 tz+2 q0^2 q2 q3 tz-2 q1^2 q2 q3 tz-2 q2^3 q3 tz-2 q0 q1 q3^2 tz+2 q2 q3^3 tz};
Print["a=",a];

solk1=solvequartic[a,k1];
Return[solk1];

]
