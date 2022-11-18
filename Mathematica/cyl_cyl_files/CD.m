(* ::Package:: *)

solvequartic[a_,k_]:=Module[{a0,a1,a2,a3,a4,ret,rt1,rt2,rt3,rt4},

{a0,a1,a2,a3,a4}=a;
rt1={k->-(1/(12 a4))(3 a3+Sqrt[3] a4 \[Sqrt](1/a4^2(3 a3^2-8 a2 a4+(4 2^(1/3) a4 (a2^2-3 a1 a3+12 a0 a4))/(2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)+2 2^(2/3) a4 (2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)))+Sqrt[6] a4 \[Sqrt](-1/a4^3(-3 a3^2 a4+8 a2 a4^2+(2 2^(1/3) a4^2 (a2^2-3 a1 a3+12 a0 a4))/(2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)+2^(2/3) a4^2 (2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)-(3 Sqrt[3] (a3^3-4 a2 a3 a4+8 a1 a4^2))/(\[Sqrt](1/a4^2(3 a3^2-8 a2 a4+(4 2^(1/3) a4 (a2^2-3 a1 a3+12 a0 a4))/(2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)+2 2^(2/3) a4 (2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)))))))};
rt2={k->1/(12 a4) (-3 a3-Sqrt[3] a4 \[Sqrt](1/a4^2(3 a3^2-8 a2 a4+(4 2^(1/3) a4 (a2^2-3 a1 a3+12 a0 a4))/(2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)+2 2^(2/3) a4 (2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)))+Sqrt[6] a4 \[Sqrt](-1/a4^3(-3 a3^2 a4+8 a2 a4^2+(2 2^(1/3) a4^2 (a2^2-3 a1 a3+12 a0 a4))/(2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)+2^(2/3) a4^2 (2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)-(3 Sqrt[3] (a3^3-4 a2 a3 a4+8 a1 a4^2))/(\[Sqrt](1/a4^2(3 a3^2-8 a2 a4+(4 2^(1/3) a4 (a2^2-3 a1 a3+12 a0 a4))/(2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)+2 2^(2/3) a4 (2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)))))))};
rt3={k->1/(12 a4) (-3 a3+Sqrt[3] a4 \[Sqrt](1/a4^2(3 a3^2-8 a2 a4+(4 2^(1/3) a4 (a2^2-3 a1 a3+12 a0 a4))/(2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)+2 2^(2/3) a4 (2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)))-Sqrt[6] a4 \[Sqrt](-1/a4^3(-3 a3^2 a4+8 a2 a4^2+(2 2^(1/3) a4^2 (a2^2-3 a1 a3+12 a0 a4))/(2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)+2^(2/3) a4^2 (2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)+(3 Sqrt[3] (a3^3-4 a2 a3 a4+8 a1 a4^2))/(\[Sqrt](1/a4^2(3 a3^2-8 a2 a4+(4 2^(1/3) a4 (a2^2-3 a1 a3+12 a0 a4))/(2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)+2 2^(2/3) a4 (2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)))))))};
rt4={k->1/(12 a4) (-3 a3+Sqrt[3] a4 \[Sqrt](1/a4^2(3 a3^2-8 a2 a4+(4 2^(1/3) a4 (a2^2-3 a1 a3+12 a0 a4))/(2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)+2 2^(2/3) a4 (2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)))+Sqrt[6] a4 \[Sqrt](-1/a4^3(-3 a3^2 a4+8 a2 a4^2+(2 2^(1/3) a4^2 (a2^2-3 a1 a3+12 a0 a4))/(2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)+2^(2/3) a4^2 (2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)+(3 Sqrt[3] (a3^3-4 a2 a3 a4+8 a1 a4^2))/(\[Sqrt](1/a4^2(3 a3^2-8 a2 a4+(4 2^(1/3) a4 (a2^2-3 a1 a3+12 a0 a4))/(2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)+2 2^(2/3) a4 (2 a2^3-9 a1 a2 a3+27 a0 a3^2+27 a1^2 a4-72 a0 a2 a4+\[Sqrt](-4 (a2^2-3 a1 a3+12 a0 a4)^3+(2 a2^3-9 a2 (a1 a3+8 a0 a4)+27 (a0 a3^2+a1^2 a4))^2))^(1/3)))))))};

Return[{rt1,rt2,rt3,rt4}];
]



cdsolt1f[\[Theta]1_,\[Theta]2_,t1_,r1_,l1_,r2_,l2_,q_,t_]:=
Module[{q0,q1,q2,q3,tx,ty,tz},

{q0,q1,q2,q3}=q;
{tx,ty,tz}=t;

Return[t1->1/r1 (tx Cos[\[Theta]1]+(q0^2-q3^2) r2 Cos[\[Theta]1-\[Theta]2]+q1^2 r2 Cos[\[Theta]1+\[Theta]2]-q2^2 r2 Cos[\[Theta]1+\[Theta]2]+ty Sin[\[Theta]1]+2 q0 q3 r2 Sin[\[Theta]1-\[Theta]2]+2 q1 q2 r2 Sin[\[Theta]1+\[Theta]2])];
]

cdsolk2f[k1_,k2_,r1_,l1_,r2_,l2_,q_,t_]:=
Module[{q0,q1,q2,q3,tx,ty,tz},

{q0,q1,q2,q3}=q;
{tx,ty,tz}=t;
Return[{k2->((24 k1 q0^4 r2-24 k1^3 q0^4 r2-24 k1 q1^4 r2+24 k1^3 q1^4 r2+24 q0^2 q1 q2 r2+48 k1^2 q0^2 q1 q2 r2+24 k1^4 q0^2 q1 q2 r2+24 q1^3 q2 r2-144 k1^2 q1^3 q2 r2+24 k1^4 q1^3 q2 r2+144 k1 q1^2 q2^2 r2-144 k1^3 q1^2 q2^2 r2-24 q1 q2^3 r2+144 k1^2 q1 q2^3 r2-24 k1^4 q1 q2^3 r2-24 k1 q2^4 r2+24 k1^3 q2^4 r2-24 q0^3 q3 r2+144 k1^2 q0^3 q3 r2-24 k1^4 q0^3 q3 r2-24 q0 q1^2 q3 r2-48 k1^2 q0 q1^2 q3 r2-24 k1^4 q0 q1^2 q3 r2+24 q0 q2^2 q3 r2+48 k1^2 q0 q2^2 q3 r2+24 k1^4 q0 q2^2 q3 r2-144 k1 q0^2 q3^2 r2+144 k1^3 q0^2 q3^2 r2-24 q1 q2 q3^2 r2-48 k1^2 q1 q2 q3^2 r2-24 k1^4 q1 q2 q3^2 r2+24 q0 q3^3 r2-144 k1^2 q0 q3^3 r2+24 k1^4 q0 q3^3 r2+24 k1 q3^4 r2-24 k1^3 q3^4 r2) (2 q1 q2 r2+2 q0 q3 r2+k1 (-2 q0^2 r2-2 q1^2 r2+2 q2^2 r2+2 q3^2 r2-2 tx)+k1^2 (-2 q1 q2 r2-2 q0 q3 r2-ty)+ty) (2 k1 q0^2 r2+2 k1 q1^2 r2-2 q1 q2 r2+2 k1^2 q1 q2 r2-2 k1 q2^2 r2-2 q0 q3 r2+2 k1^2 q0 q3 r2-2 k1 q3^2 r2-2 k1 tx+ty-k1^2 ty)^2-(2 q0^2 r2-2 k1^2 q0^2 r2-2 q1^2 r2+2 k1^2 q1^2 r2-8 k1 q1 q2 r2+2 q2^2 r2-2 k1^2 q2^2 r2+8 k1 q0 q3 r2-2 q3^2 r2+2 k1^2 q3^2 r2) (2 q1 q2 r2+2 q0 q3 r2+k1 (-2 q0^2 r2-2 q1^2 r2+2 q2^2 r2+2 q3^2 r2-2 tx)+k1^2 (-2 q1 q2 r2-2 q0 q3 r2-ty)+ty) (2 k1 q0^2 r2+2 k1 q1^2 r2-2 q1 q2 r2+2 k1^2 q1 q2 r2-2 k1 q2^2 r2-2 q0 q3 r2+2 k1^2 q0 q3 r2-2 k1 q3^2 r2-2 k1 tx+ty-k1^2 ty) (-4 q0^4 r2+24 k1^2 q0^4 r2-4 k1^4 q0^4 r2-8 q0^2 q1^2 r2-16 k1^2 q0^2 q1^2 r2-8 k1^4 q0^2 q1^2 r2-4 q1^4 r2+24 k1^2 q1^4 r2-4 k1^4 q1^4 r2-64 k1 q1^3 q2 r2+64 k1^3 q1^3 q2 r2+8 q0^2 q2^2 r2+16 k1^2 q0^2 q2^2 r2+8 k1^4 q0^2 q2^2 r2+24 q1^2 q2^2 r2-144 k1^2 q1^2 q2^2 r2+24 k1^4 q1^2 q2^2 r2+64 k1 q1 q2^3 r2-64 k1^3 q1 q2^3 r2-4 q2^4 r2+24 k1^2 q2^4 r2-4 k1^4 q2^4 r2-64 k1 q0^3 q3 r2+64 k1^3 q0^3 q3 r2-32 q0 q1 q2 q3 r2-64 k1^2 q0 q1 q2 q3 r2-32 k1^4 q0 q1 q2 q3 r2+24 q0^2 q3^2 r2-144 k1^2 q0^2 q3^2 r2+24 k1^4 q0^2 q3^2 r2+8 q1^2 q3^2 r2+16 k1^2 q1^2 q3^2 r2+8 k1^4 q1^2 q3^2 r2-8 q2^2 q3^2 r2-16 k1^2 q2^2 q3^2 r2-8 k1^4 q2^2 q3^2 r2+64 k1 q0 q3^3 r2-64 k1^3 q0 q3^3 r2-4 q3^4 r2+24 k1^2 q3^4 r2-4 k1^4 q3^4 r2-16 k1^2 q0^2 tx-16 k1^2 q1^2 tx+16 k1 q1 q2 tx-16 k1^3 q1 q2 tx+16 k1^2 q2^2 tx+16 k1 q0 q3 tx-16 k1^3 q0 q3 tx+16 k1^2 q3^2 tx+8 k1 q0^2 ty-8 k1^3 q0^2 ty+8 k1 q1^2 ty-8 k1^3 q1^2 ty-8 q1 q2 ty+16 k1^2 q1 q2 ty-8 k1^4 q1 q2 ty-8 k1 q2^2 ty+8 k1^3 q2^2 ty-8 q0 q3 ty+16 k1^2 q0 q3 ty-8 k1^4 q0 q3 ty-8 k1 q3^2 ty+8 k1^3 q3^2 ty+8 q0 q2 tz+16 k1^2 q0 q2 tz+8 k1^4 q0 q2 tz-8 q1 q3 tz-16 k1^2 q1 q3 tz-8 k1^4 q1 q3 tz)+(2 q0^2 r2-2 k1^2 q0^2 r2-2 q1^2 r2+2 k1^2 q1^2 r2-8 k1 q1 q2 r2+2 q2^2 r2-2 k1^2 q2^2 r2+8 k1 q0 q3 r2-2 q3^2 r2+2 k1^2 q3^2 r2)^2 (2 q1 q2 r2+2 q0 q3 r2+k1 (-2 q0^2 r2-2 q1^2 r2+2 q2^2 r2+2 q3^2 r2-2 tx)+k1^2 (-2 q1 q2 r2-2 q0 q3 r2-ty)+ty) (-4 k1 q0^4 r2+4 k1^3 q0^4 r2+4 k1 q1^4 r2-4 k1^3 q1^4 r2-4 q0^2 q1 q2 r2-8 k1^2 q0^2 q1 q2 r2-4 k1^4 q0^2 q1 q2 r2-4 q1^3 q2 r2+24 k1^2 q1^3 q2 r2-4 k1^4 q1^3 q2 r2-24 k1 q1^2 q2^2 r2+24 k1^3 q1^2 q2^2 r2+4 q1 q2^3 r2-24 k1^2 q1 q2^3 r2+4 k1^4 q1 q2^3 r2+4 k1 q2^4 r2-4 k1^3 q2^4 r2+4 q0^3 q3 r2-24 k1^2 q0^3 q3 r2+4 k1^4 q0^3 q3 r2+4 q0 q1^2 q3 r2+8 k1^2 q0 q1^2 q3 r2+4 k1^4 q0 q1^2 q3 r2-4 q0 q2^2 q3 r2-8 k1^2 q0 q2^2 q3 r2-4 k1^4 q0 q2^2 q3 r2+24 k1 q0^2 q3^2 r2-24 k1^3 q0^2 q3^2 r2+4 q1 q2 q3^2 r2+8 k1^2 q1 q2 q3^2 r2+4 k1^4 q1 q2 q3^2 r2-4 q0 q3^3 r2+24 k1^2 q0 q3^3 r2-4 k1^4 q0 q3^3 r2-4 k1 q3^4 r2+4 k1^3 q3^4 r2+4 k1 q0^2 tx-4 k1^3 q0^2 tx-4 k1 q1^2 tx+4 k1^3 q1^2 tx-16 k1^2 q1 q2 tx+4 k1 q2^2 tx-4 k1^3 q2^2 tx+16 k1^2 q0 q3 tx-4 k1 q3^2 tx+4 k1^3 q3^2 tx-2 q0^2 ty+4 k1^2 q0^2 ty-2 k1^4 q0^2 ty+2 q1^2 ty-4 k1^2 q1^2 ty+2 k1^4 q1^2 ty+8 k1 q1 q2 ty-8 k1^3 q1 q2 ty-2 q2^2 ty+4 k1^2 q2^2 ty-2 k1^4 q2^2 ty-8 k1 q0 q3 ty+8 k1^3 q0 q3 ty+2 q3^2 ty-4 k1^2 q3^2 ty+2 k1^4 q3^2 ty-4 q0 q1 tz-8 k1^2 q0 q1 tz-4 k1^4 q0 q1 tz-4 q2 q3 tz-8 k1^2 q2 q3 tz-4 k1^4 q2 q3 tz)-(2 q1 q2 r2+2 q0 q3 r2+k1 (-2 q0^2 r2-2 q1^2 r2+2 q2^2 r2+2 q3^2 r2-2 tx)+k1^2 (-2 q1 q2 r2-2 q0 q3 r2-ty)+ty)^2 (2 k1 q0^2 r2+2 k1 q1^2 r2-2 q1 q2 r2+2 k1^2 q1 q2 r2-2 k1 q2^2 r2-2 q0 q3 r2+2 k1^2 q0 q3 r2-2 k1 q3^2 r2-2 k1 tx+ty-k1^2 ty) (-4 k1 q0^4 r2+4 k1^3 q0^4 r2+4 k1 q1^4 r2-4 k1^3 q1^4 r2-4 q0^2 q1 q2 r2-8 k1^2 q0^2 q1 q2 r2-4 k1^4 q0^2 q1 q2 r2-4 q1^3 q2 r2+24 k1^2 q1^3 q2 r2-4 k1^4 q1^3 q2 r2-24 k1 q1^2 q2^2 r2+24 k1^3 q1^2 q2^2 r2+4 q1 q2^3 r2-24 k1^2 q1 q2^3 r2+4 k1^4 q1 q2^3 r2+4 k1 q2^4 r2-4 k1^3 q2^4 r2+4 q0^3 q3 r2-24 k1^2 q0^3 q3 r2+4 k1^4 q0^3 q3 r2+4 q0 q1^2 q3 r2+8 k1^2 q0 q1^2 q3 r2+4 k1^4 q0 q1^2 q3 r2-4 q0 q2^2 q3 r2-8 k1^2 q0 q2^2 q3 r2-4 k1^4 q0 q2^2 q3 r2+24 k1 q0^2 q3^2 r2-24 k1^3 q0^2 q3^2 r2+4 q1 q2 q3^2 r2+8 k1^2 q1 q2 q3^2 r2+4 k1^4 q1 q2 q3^2 r2-4 q0 q3^3 r2+24 k1^2 q0 q3^3 r2-4 k1^4 q0 q3^3 r2-4 k1 q3^4 r2+4 k1^3 q3^4 r2+4 k1 q0^2 tx-4 k1^3 q0^2 tx-4 k1 q1^2 tx+4 k1^3 q1^2 tx-16 k1^2 q1 q2 tx+4 k1 q2^2 tx-4 k1^3 q2^2 tx+16 k1^2 q0 q3 tx-4 k1 q3^2 tx+4 k1^3 q3^2 tx-2 q0^2 ty+4 k1^2 q0^2 ty-2 k1^4 q0^2 ty+2 q1^2 ty-4 k1^2 q1^2 ty+2 k1^4 q1^2 ty+8 k1 q1 q2 ty-8 k1^3 q1 q2 ty-2 q2^2 ty+4 k1^2 q2^2 ty-2 k1^4 q2^2 ty-8 k1 q0 q3 ty+8 k1^3 q0 q3 ty+2 q3^2 ty-4 k1^2 q3^2 ty+2 k1^4 q3^2 ty-4 q0 q1 tz-8 k1^2 q0 q1 tz-4 k1^4 q0 q1 tz-4 q2 q3 tz-8 k1^2 q2 q3 tz-4 k1^4 q2 q3 tz)-(2 k1 q0^2 r2+2 k1 q1^2 r2-2 q1 q2 r2+2 k1^2 q1 q2 r2-2 k1 q2^2 r2-2 q0 q3 r2+2 k1^2 q0 q3 r2-2 k1 q3^2 r2-2 k1 tx+ty-k1^2 ty)^3 (2 k1^3 (2 q0^4 r2-2 q1^4 r2+12 q1^2 q2^2 r2-2 q2^4 r2-12 q0^2 q3^2 r2+2 q3^4 r2+2 q0^2 tx-2 q1^2 tx+2 q2^2 tx-2 q3^2 tx+4 q1 q2 ty-4 q0 q3 ty)+2 k1 (-2 q0^4 r2+2 q1^4 r2-12 q1^2 q2^2 r2+2 q2^4 r2+12 q0^2 q3^2 r2-2 q3^4 r2-2 q0^2 tx+2 q1^2 tx-2 q2^2 tx+2 q3^2 tx-4 q1 q2 ty+4 q0 q3 ty)+2 (-2 q0^2 q1 q2 r2-2 q1^3 q2 r2+2 q1 q2^3 r2+2 q0^3 q3 r2+2 q0 q1^2 q3 r2-2 q0 q2^2 q3 r2+2 q1 q2 q3^2 r2-2 q0 q3^3 r2+q0^2 ty-q1^2 ty+q2^2 ty-q3^2 ty+2 q0 q1 tz+2 q2 q3 tz)+2 k1^4 (-2 q0^2 q1 q2 r2-2 q1^3 q2 r2+2 q1 q2^3 r2+2 q0^3 q3 r2+2 q0 q1^2 q3 r2-2 q0 q2^2 q3 r2+2 q1 q2 q3^2 r2-2 q0 q3^3 r2+q0^2 ty-q1^2 ty+q2^2 ty-q3^2 ty+2 q0 q1 tz+2 q2 q3 tz)+2 k1^2 (-4 q0^2 q1 q2 r2+12 q1^3 q2 r2-12 q1 q2^3 r2-12 q0^3 q3 r2+4 q0 q1^2 q3 r2-4 q0 q2^2 q3 r2+4 q1 q2 q3^2 r2+12 q0 q3^3 r2+8 q1 q2 tx-8 q0 q3 tx-2 q0^2 ty+2 q1^2 ty-2 q2^2 ty+2 q3^2 ty+4 q0 q1 tz+4 q2 q3 tz)))/(-(2 q0^2 r2-2 k1^2 q0^2 r2-2 q1^2 r2+2 k1^2 q1^2 r2-8 k1 q1 q2 r2+2 q2^2 r2-2 k1^2 q2^2 r2+8 k1 q0 q3 r2-2 q3^2 r2+2 k1^2 q3^2 r2) (24 k1 q0^4 r2-24 k1^3 q0^4 r2-24 k1 q1^4 r2+24 k1^3 q1^4 r2+24 q0^2 q1 q2 r2+48 k1^2 q0^2 q1 q2 r2+24 k1^4 q0^2 q1 q2 r2+24 q1^3 q2 r2-144 k1^2 q1^3 q2 r2+24 k1^4 q1^3 q2 r2+144 k1 q1^2 q2^2 r2-144 k1^3 q1^2 q2^2 r2-24 q1 q2^3 r2+144 k1^2 q1 q2^3 r2-24 k1^4 q1 q2^3 r2-24 k1 q2^4 r2+24 k1^3 q2^4 r2-24 q0^3 q3 r2+144 k1^2 q0^3 q3 r2-24 k1^4 q0^3 q3 r2-24 q0 q1^2 q3 r2-48 k1^2 q0 q1^2 q3 r2-24 k1^4 q0 q1^2 q3 r2+24 q0 q2^2 q3 r2+48 k1^2 q0 q2^2 q3 r2+24 k1^4 q0 q2^2 q3 r2-144 k1 q0^2 q3^2 r2+144 k1^3 q0^2 q3^2 r2-24 q1 q2 q3^2 r2-48 k1^2 q1 q2 q3^2 r2-24 k1^4 q1 q2 q3^2 r2+24 q0 q3^3 r2-144 k1^2 q0 q3^3 r2+24 k1^4 q0 q3^3 r2+24 k1 q3^4 r2-24 k1^3 q3^4 r2) (2 k1 q0^2 r2+2 k1 q1^2 r2-2 q1 q2 r2+2 k1^2 q1 q2 r2-2 k1 q2^2 r2-2 q0 q3 r2+2 k1^2 q0 q3 r2-2 k1 q3^2 r2-2 k1 tx+ty-k1^2 ty)^2+(2 q0^2 r2-2 k1^2 q0^2 r2-2 q1^2 r2+2 k1^2 q1^2 r2-8 k1 q1 q2 r2+2 q2^2 r2-2 k1^2 q2^2 r2+8 k1 q0 q3 r2-2 q3^2 r2+2 k1^2 q3^2 r2)^2 (2 k1 q0^2 r2+2 k1 q1^2 r2-2 q1 q2 r2+2 k1^2 q1 q2 r2-2 k1 q2^2 r2-2 q0 q3 r2+2 k1^2 q0 q3 r2-2 k1 q3^2 r2-2 k1 tx+ty-k1^2 ty) (-4 q0^4 r2+24 k1^2 q0^4 r2-4 k1^4 q0^4 r2-8 q0^2 q1^2 r2-16 k1^2 q0^2 q1^2 r2-8 k1^4 q0^2 q1^2 r2-4 q1^4 r2+24 k1^2 q1^4 r2-4 k1^4 q1^4 r2-64 k1 q1^3 q2 r2+64 k1^3 q1^3 q2 r2+8 q0^2 q2^2 r2+16 k1^2 q0^2 q2^2 r2+8 k1^4 q0^2 q2^2 r2+24 q1^2 q2^2 r2-144 k1^2 q1^2 q2^2 r2+24 k1^4 q1^2 q2^2 r2+64 k1 q1 q2^3 r2-64 k1^3 q1 q2^3 r2-4 q2^4 r2+24 k1^2 q2^4 r2-4 k1^4 q2^4 r2-64 k1 q0^3 q3 r2+64 k1^3 q0^3 q3 r2-32 q0 q1 q2 q3 r2-64 k1^2 q0 q1 q2 q3 r2-32 k1^4 q0 q1 q2 q3 r2+24 q0^2 q3^2 r2-144 k1^2 q0^2 q3^2 r2+24 k1^4 q0^2 q3^2 r2+8 q1^2 q3^2 r2+16 k1^2 q1^2 q3^2 r2+8 k1^4 q1^2 q3^2 r2-8 q2^2 q3^2 r2-16 k1^2 q2^2 q3^2 r2-8 k1^4 q2^2 q3^2 r2+64 k1 q0 q3^3 r2-64 k1^3 q0 q3^3 r2-4 q3^4 r2+24 k1^2 q3^4 r2-4 k1^4 q3^4 r2-16 k1^2 q0^2 tx-16 k1^2 q1^2 tx+16 k1 q1 q2 tx-16 k1^3 q1 q2 tx+16 k1^2 q2^2 tx+16 k1 q0 q3 tx-16 k1^3 q0 q3 tx+16 k1^2 q3^2 tx+8 k1 q0^2 ty-8 k1^3 q0^2 ty+8 k1 q1^2 ty-8 k1^3 q1^2 ty-8 q1 q2 ty+16 k1^2 q1 q2 ty-8 k1^4 q1 q2 ty-8 k1 q2^2 ty+8 k1^3 q2^2 ty-8 q0 q3 ty+16 k1^2 q0 q3 ty-8 k1^4 q0 q3 ty-8 k1 q3^2 ty+8 k1^3 q3^2 ty+8 q0 q2 tz+16 k1^2 q0 q2 tz+8 k1^4 q0 q2 tz-8 q1 q3 tz-16 k1^2 q1 q3 tz-8 k1^4 q1 q3 tz)-(2 q1 q2 r2+2 q0 q3 r2+k1 (-2 q0^2 r2-2 q1^2 r2+2 q2^2 r2+2 q3^2 r2-2 tx)+k1^2 (-2 q1 q2 r2-2 q0 q3 r2-ty)+ty) (2 k1 q0^2 r2+2 k1 q1^2 r2-2 q1 q2 r2+2 k1^2 q1 q2 r2-2 k1 q2^2 r2-2 q0 q3 r2+2 k1^2 q0 q3 r2-2 k1 q3^2 r2-2 k1 tx+ty-k1^2 ty)^2 (-4 q0^4 r2+24 k1^2 q0^4 r2-4 k1^4 q0^4 r2-8 q0^2 q1^2 r2-16 k1^2 q0^2 q1^2 r2-8 k1^4 q0^2 q1^2 r2-4 q1^4 r2+24 k1^2 q1^4 r2-4 k1^4 q1^4 r2-64 k1 q1^3 q2 r2+64 k1^3 q1^3 q2 r2+8 q0^2 q2^2 r2+16 k1^2 q0^2 q2^2 r2+8 k1^4 q0^2 q2^2 r2+24 q1^2 q2^2 r2-144 k1^2 q1^2 q2^2 r2+24 k1^4 q1^2 q2^2 r2+64 k1 q1 q2^3 r2-64 k1^3 q1 q2^3 r2-4 q2^4 r2+24 k1^2 q2^4 r2-4 k1^4 q2^4 r2-64 k1 q0^3 q3 r2+64 k1^3 q0^3 q3 r2-32 q0 q1 q2 q3 r2-64 k1^2 q0 q1 q2 q3 r2-32 k1^4 q0 q1 q2 q3 r2+24 q0^2 q3^2 r2-144 k1^2 q0^2 q3^2 r2+24 k1^4 q0^2 q3^2 r2+8 q1^2 q3^2 r2+16 k1^2 q1^2 q3^2 r2+8 k1^4 q1^2 q3^2 r2-8 q2^2 q3^2 r2-16 k1^2 q2^2 q3^2 r2-8 k1^4 q2^2 q3^2 r2+64 k1 q0 q3^3 r2-64 k1^3 q0 q3^3 r2-4 q3^4 r2+24 k1^2 q3^4 r2-4 k1^4 q3^4 r2-16 k1^2 q0^2 tx-16 k1^2 q1^2 tx+16 k1 q1 q2 tx-16 k1^3 q1 q2 tx+16 k1^2 q2^2 tx+16 k1 q0 q3 tx-16 k1^3 q0 q3 tx+16 k1^2 q3^2 tx+8 k1 q0^2 ty-8 k1^3 q0^2 ty+8 k1 q1^2 ty-8 k1^3 q1^2 ty-8 q1 q2 ty+16 k1^2 q1 q2 ty-8 k1^4 q1 q2 ty-8 k1 q2^2 ty+8 k1^3 q2^2 ty-8 q0 q3 ty+16 k1^2 q0 q3 ty-8 k1^4 q0 q3 ty-8 k1 q3^2 ty+8 k1^3 q3^2 ty+8 q0 q2 tz+16 k1^2 q0 q2 tz+8 k1^4 q0 q2 tz-8 q1 q3 tz-16 k1^2 q1 q3 tz-8 k1^4 q1 q3 tz)+(2 k1 q0^2 r2+2 k1 q1^2 r2-2 q1 q2 r2+2 k1^2 q1 q2 r2-2 k1 q2^2 r2-2 q0 q3 r2+2 k1^2 q0 q3 r2-2 k1 q3^2 r2-2 k1 tx+ty-k1^2 ty)^3 (4 q0^4 r2-24 k1^2 q0^4 r2+4 k1^4 q0^4 r2+8 q0^2 q1^2 r2+16 k1^2 q0^2 q1^2 r2+8 k1^4 q0^2 q1^2 r2+4 q1^4 r2-24 k1^2 q1^4 r2+4 k1^4 q1^4 r2+64 k1 q1^3 q2 r2-64 k1^3 q1^3 q2 r2-8 q0^2 q2^2 r2-16 k1^2 q0^2 q2^2 r2-8 k1^4 q0^2 q2^2 r2-24 q1^2 q2^2 r2+144 k1^2 q1^2 q2^2 r2-24 k1^4 q1^2 q2^2 r2-64 k1 q1 q2^3 r2+64 k1^3 q1 q2^3 r2+4 q2^4 r2-24 k1^2 q2^4 r2+4 k1^4 q2^4 r2+64 k1 q0^3 q3 r2-64 k1^3 q0^3 q3 r2+32 q0 q1 q2 q3 r2+64 k1^2 q0 q1 q2 q3 r2+32 k1^4 q0 q1 q2 q3 r2-24 q0^2 q3^2 r2+144 k1^2 q0^2 q3^2 r2-24 k1^4 q0^2 q3^2 r2-8 q1^2 q3^2 r2-16 k1^2 q1^2 q3^2 r2-8 k1^4 q1^2 q3^2 r2+8 q2^2 q3^2 r2+16 k1^2 q2^2 q3^2 r2+8 k1^4 q2^2 q3^2 r2-64 k1 q0 q3^3 r2+64 k1^3 q0 q3^3 r2+4 q3^4 r2-24 k1^2 q3^4 r2+4 k1^4 q3^4 r2-16 k1^2 q0^2 tx-16 k1^2 q1^2 tx+16 k1 q1 q2 tx-16 k1^3 q1 q2 tx+16 k1^2 q2^2 tx+16 k1 q0 q3 tx-16 k1^3 q0 q3 tx+16 k1^2 q3^2 tx+8 k1 q0^2 ty-8 k1^3 q0^2 ty+8 k1 q1^2 ty-8 k1^3 q1^2 ty-8 q1 q2 ty+16 k1^2 q1 q2 ty-8 k1^4 q1 q2 ty-8 k1 q2^2 ty+8 k1^3 q2^2 ty-8 q0 q3 ty+16 k1^2 q0 q3 ty-8 k1^4 q0 q3 ty-8 k1 q3^2 ty+8 k1^3 q3^2 ty+8 q0 q2 tz+16 k1^2 q0 q2 tz+8 k1^4 q0 q2 tz-8 q1 q3 tz-16 k1^2 q1 q3 tz-8 k1^4 q1 q3 tz)-(2 q0^2 r2-2 k1^2 q0^2 r2-2 q1^2 r2+2 k1^2 q1^2 r2-8 k1 q1 q2 r2+2 q2^2 r2-2 k1^2 q2^2 r2+8 k1 q0 q3 r2-2 q3^2 r2+2 k1^2 q3^2 r2)^3 (-4 k1 q0^4 r2+4 k1^3 q0^4 r2+4 k1 q1^4 r2-4 k1^3 q1^4 r2-4 q0^2 q1 q2 r2-8 k1^2 q0^2 q1 q2 r2-4 k1^4 q0^2 q1 q2 r2-4 q1^3 q2 r2+24 k1^2 q1^3 q2 r2-4 k1^4 q1^3 q2 r2-24 k1 q1^2 q2^2 r2+24 k1^3 q1^2 q2^2 r2+4 q1 q2^3 r2-24 k1^2 q1 q2^3 r2+4 k1^4 q1 q2^3 r2+4 k1 q2^4 r2-4 k1^3 q2^4 r2+4 q0^3 q3 r2-24 k1^2 q0^3 q3 r2+4 k1^4 q0^3 q3 r2+4 q0 q1^2 q3 r2+8 k1^2 q0 q1^2 q3 r2+4 k1^4 q0 q1^2 q3 r2-4 q0 q2^2 q3 r2-8 k1^2 q0 q2^2 q3 r2-4 k1^4 q0 q2^2 q3 r2+24 k1 q0^2 q3^2 r2-24 k1^3 q0^2 q3^2 r2+4 q1 q2 q3^2 r2+8 k1^2 q1 q2 q3^2 r2+4 k1^4 q1 q2 q3^2 r2-4 q0 q3^3 r2+24 k1^2 q0 q3^3 r2-4 k1^4 q0 q3^3 r2-4 k1 q3^4 r2+4 k1^3 q3^4 r2+4 k1 q0^2 tx-4 k1^3 q0^2 tx-4 k1 q1^2 tx+4 k1^3 q1^2 tx-16 k1^2 q1 q2 tx+4 k1 q2^2 tx-4 k1^3 q2^2 tx+16 k1^2 q0 q3 tx-4 k1 q3^2 tx+4 k1^3 q3^2 tx-2 q0^2 ty+4 k1^2 q0^2 ty-2 k1^4 q0^2 ty+2 q1^2 ty-4 k1^2 q1^2 ty+2 k1^4 q1^2 ty+8 k1 q1 q2 ty-8 k1^3 q1 q2 ty-2 q2^2 ty+4 k1^2 q2^2 ty-2 k1^4 q2^2 ty-8 k1 q0 q3 ty+8 k1^3 q0 q3 ty+2 q3^2 ty-4 k1^2 q3^2 ty+2 k1^4 q3^2 ty-4 q0 q1 tz-8 k1^2 q0 q1 tz-4 k1^4 q0 q1 tz-4 q2 q3 tz-8 k1^2 q2 q3 tz-4 k1^4 q2 q3 tz)+2 (2 q0^2 r2-2 k1^2 q0^2 r2-2 q1^2 r2+2 k1^2 q1^2 r2-8 k1 q1 q2 r2+2 q2^2 r2-2 k1^2 q2^2 r2+8 k1 q0 q3 r2-2 q3^2 r2+2 k1^2 q3^2 r2) (2 q1 q2 r2+2 q0 q3 r2+k1 (-2 q0^2 r2-2 q1^2 r2+2 q2^2 r2+2 q3^2 r2-2 tx)+k1^2 (-2 q1 q2 r2-2 q0 q3 r2-ty)+ty) (2 k1 q0^2 r2+2 k1 q1^2 r2-2 q1 q2 r2+2 k1^2 q1 q2 r2-2 k1 q2^2 r2-2 q0 q3 r2+2 k1^2 q0 q3 r2-2 k1 q3^2 r2-2 k1 tx+ty-k1^2 ty) (-4 k1 q0^4 r2+4 k1^3 q0^4 r2+4 k1 q1^4 r2-4 k1^3 q1^4 r2-4 q0^2 q1 q2 r2-8 k1^2 q0^2 q1 q2 r2-4 k1^4 q0^2 q1 q2 r2-4 q1^3 q2 r2+24 k1^2 q1^3 q2 r2-4 k1^4 q1^3 q2 r2-24 k1 q1^2 q2^2 r2+24 k1^3 q1^2 q2^2 r2+4 q1 q2^3 r2-24 k1^2 q1 q2^3 r2+4 k1^4 q1 q2^3 r2+4 k1 q2^4 r2-4 k1^3 q2^4 r2+4 q0^3 q3 r2-24 k1^2 q0^3 q3 r2+4 k1^4 q0^3 q3 r2+4 q0 q1^2 q3 r2+8 k1^2 q0 q1^2 q3 r2+4 k1^4 q0 q1^2 q3 r2-4 q0 q2^2 q3 r2-8 k1^2 q0 q2^2 q3 r2-4 k1^4 q0 q2^2 q3 r2+24 k1 q0^2 q3^2 r2-24 k1^3 q0^2 q3^2 r2+4 q1 q2 q3^2 r2+8 k1^2 q1 q2 q3^2 r2+4 k1^4 q1 q2 q3^2 r2-4 q0 q3^3 r2+24 k1^2 q0 q3^3 r2-4 k1^4 q0 q3^3 r2-4 k1 q3^4 r2+4 k1^3 q3^4 r2+4 k1 q0^2 tx-4 k1^3 q0^2 tx-4 k1 q1^2 tx+4 k1^3 q1^2 tx-16 k1^2 q1 q2 tx+4 k1 q2^2 tx-4 k1^3 q2^2 tx+16 k1^2 q0 q3 tx-4 k1 q3^2 tx+4 k1^3 q3^2 tx-2 q0^2 ty+4 k1^2 q0^2 ty-2 k1^4 q0^2 ty+2 q1^2 ty-4 k1^2 q1^2 ty+2 k1^4 q1^2 ty+8 k1 q1 q2 ty-8 k1^3 q1 q2 ty-2 q2^2 ty+4 k1^2 q2^2 ty-2 k1^4 q2^2 ty-8 k1 q0 q3 ty+8 k1^3 q0 q3 ty+2 q3^2 ty-4 k1^2 q3^2 ty+2 k1^4 q3^2 ty-4 q0 q1 tz-8 k1^2 q0 q1 tz-4 k1^4 q0 q1 tz-4 q2 q3 tz-8 k1^2 q2 q3 tz-4 k1^4 q2 q3 tz))}];
]


cdsolk1f[k1_,r1_,l1_,r2_,l2_,q_,t_]:=
Module[{b,a,q0,q1,q2,q3,tx,ty,tz,solk11,solk12,solk1,solk13,solk14,solk15,solk16,solk17,solk18},
{q0,q1,q2,q3}=q;
{tx,ty,tz}=t;

a={q0^6 q1^2 r2^2-2 q0^4 q1^4 r2^2+q0^2 q1^6 r2^2-2 q0^4 q1^2 q2^2 r2^2+2 q0^2 q1^4 q2^2 r2^2+q0^2 q1^2 q2^4 r2^2-2 q0^5 q1 q2 q3 r2^2+4 q0^3 q1^3 q2 q3 r2^2-2 q0 q1^5 q2 q3 r2^2+4 q0^3 q1 q2^3 q3 r2^2-4 q0 q1^3 q2^3 q3 r2^2-2 q0 q1 q2^5 q3 r2^2+2 q0^4 q1^2 q3^2 r2^2-2 q0^2 q1^4 q3^2 r2^2+q0^4 q2^2 q3^2 r2^2-4 q0^2 q1^2 q2^2 q3^2 r2^2+q1^4 q2^2 q3^2 r2^2-2 q0^2 q2^4 q3^2 r2^2+2 q1^2 q2^4 q3^2 r2^2+q2^6 q3^2 r2^2-4 q0^3 q1 q2 q3^3 r2^2+4 q0 q1^3 q2 q3^3 r2^2+4 q0 q1 q2^3 q3^3 r2^2+q0^2 q1^2 q3^4 r2^2+2 q0^2 q2^2 q3^4 r2^2-2 q1^2 q2^2 q3^4 r2^2-2 q2^4 q3^4 r2^2-2 q0 q1 q2 q3^5 r2^2+q2^2 q3^6 r2^2-q0^2 q1^2 ty^2-q0^2 q2^2 ty^2-q1^2 q3^2 ty^2-q2^2 q3^2 ty^2,4 q0^6 q1 q2 r2^2-8 q0^4 q1^3 q2 r2^2+4 q0^2 q1^5 q2 r2^2-8 q0^4 q1 q2^3 r2^2+8 q0^2 q1^3 q2^3 r2^2+4 q0^2 q1 q2^5 r2^2+4 q0^5 q1^2 q3 r2^2-8 q0^3 q1^4 q3 r2^2+4 q0 q1^6 q3 r2^2-4 q0^5 q2^2 q3 r2^2+4 q0 q1^4 q2^2 q3 r2^2+8 q0^3 q2^4 q3 r2^2-4 q0 q1^2 q2^4 q3 r2^2-4 q0 q2^6 q3 r2^2+4 q0^4 q1 q2 q3^2 r2^2-4 q1^5 q2 q3^2 r2^2-8 q1^3 q2^3 q3^2 r2^2-4 q1 q2^5 q3^2 r2^2+8 q0^3 q1^2 q3^3 r2^2-8 q0 q1^4 q3^3 r2^2-8 q0^3 q2^2 q3^3 r2^2+8 q0 q2^4 q3^3 r2^2-4 q0^2 q1 q2 q3^4 r2^2+8 q1^3 q2 q3^4 r2^2+8 q1 q2^3 q3^4 r2^2+4 q0 q1^2 q3^5 r2^2-4 q0 q2^2 q3^5 r2^2-4 q1 q2 q3^6 r2^2+4 q0^2 q1^2 tx ty+4 q0^2 q2^2 tx ty+4 q1^2 q3^2 tx ty+4 q2^2 q3^2 tx ty,-2 q0^6 q1^2 r2^2+4 q0^4 q1^4 r2^2-2 q0^2 q1^6 r2^2+4 q0^6 q2^2 r2^2-4 q0^4 q1^2 q2^2 r2^2-8 q0^4 q2^4 r2^2+6 q0^2 q1^2 q2^4 r2^2+4 q0^2 q2^6 r2^2+12 q0^5 q1 q2 q3 r2^2-24 q0^3 q1^3 q2 q3 r2^2+12 q0 q1^5 q2 q3 r2^2-24 q0^3 q1 q2^3 q3 r2^2+24 q0 q1^3 q2^3 q3 r2^2+12 q0 q1 q2^5 q3 r2^2-4 q0^2 q1^4 q3^2 r2^2+4 q1^6 q3^2 r2^2+6 q0^4 q2^2 q3^2 r2^2-8 q0^2 q1^2 q2^2 q3^2 r2^2+6 q1^4 q2^2 q3^2 r2^2-4 q0^2 q2^4 q3^2 r2^2-2 q2^6 q3^2 r2^2+24 q0^3 q1 q2 q3^3 r2^2-24 q0 q1^3 q2 q3^3 r2^2-24 q0 q1 q2^3 q3^3 r2^2+6 q0^2 q1^2 q3^4 r2^2-8 q1^4 q3^4 r2^2-4 q1^2 q2^2 q3^4 r2^2+4 q2^4 q3^4 r2^2+12 q0 q1 q2 q3^5 r2^2+4 q1^2 q3^6 r2^2-2 q2^2 q3^6 r2^2-4 q0^2 q1^2 tx^2-4 q0^2 q2^2 tx^2-4 q1^2 q3^2 tx^2-4 q2^2 q3^2 tx^2+2 q0^2 q1^2 ty^2+2 q0^2 q2^2 ty^2+2 q1^2 q3^2 ty^2+2 q2^2 q3^2 ty^2,-4 q0^6 q1 q2 r2^2+8 q0^4 q1^3 q2 r2^2-4 q0^2 q1^5 q2 r2^2+8 q0^4 q1 q2^3 r2^2-8 q0^2 q1^3 q2^3 r2^2-4 q0^2 q1 q2^5 r2^2-4 q0^5 q1^2 q3 r2^2+8 q0^3 q1^4 q3 r2^2-4 q0 q1^6 q3 r2^2+4 q0^5 q2^2 q3 r2^2-4 q0 q1^4 q2^2 q3 r2^2-8 q0^3 q2^4 q3 r2^2+4 q0 q1^2 q2^4 q3 r2^2+4 q0 q2^6 q3 r2^2-4 q0^4 q1 q2 q3^2 r2^2+4 q1^5 q2 q3^2 r2^2+8 q1^3 q2^3 q3^2 r2^2+4 q1 q2^5 q3^2 r2^2-8 q0^3 q1^2 q3^3 r2^2+8 q0 q1^4 q3^3 r2^2+8 q0^3 q2^2 q3^3 r2^2-8 q0 q2^4 q3^3 r2^2+4 q0^2 q1 q2 q3^4 r2^2-8 q1^3 q2 q3^4 r2^2-8 q1 q2^3 q3^4 r2^2-4 q0 q1^2 q3^5 r2^2+4 q0 q2^2 q3^5 r2^2+4 q1 q2 q3^6 r2^2-4 q0^2 q1^2 tx ty-4 q0^2 q2^2 tx ty-4 q1^2 q3^2 tx ty-4 q2^2 q3^2 tx ty,q0^6 q1^2 r2^2-2 q0^4 q1^4 r2^2+q0^2 q1^6 r2^2-2 q0^4 q1^2 q2^2 r2^2+2 q0^2 q1^4 q2^2 r2^2+q0^2 q1^2 q2^4 r2^2-2 q0^5 q1 q2 q3 r2^2+4 q0^3 q1^3 q2 q3 r2^2-2 q0 q1^5 q2 q3 r2^2+4 q0^3 q1 q2^3 q3 r2^2-4 q0 q1^3 q2^3 q3 r2^2-2 q0 q1 q2^5 q3 r2^2+2 q0^4 q1^2 q3^2 r2^2-2 q0^2 q1^4 q3^2 r2^2+q0^4 q2^2 q3^2 r2^2-4 q0^2 q1^2 q2^2 q3^2 r2^2+q1^4 q2^2 q3^2 r2^2-2 q0^2 q2^4 q3^2 r2^2+2 q1^2 q2^4 q3^2 r2^2+q2^6 q3^2 r2^2-4 q0^3 q1 q2 q3^3 r2^2+4 q0 q1^3 q2 q3^3 r2^2+4 q0 q1 q2^3 q3^3 r2^2+q0^2 q1^2 q3^4 r2^2+2 q0^2 q2^2 q3^4 r2^2-2 q1^2 q2^2 q3^4 r2^2-2 q2^4 q3^4 r2^2-2 q0 q1 q2 q3^5 r2^2+q2^2 q3^6 r2^2-q0^2 q1^2 ty^2-q0^2 q2^2 ty^2-q1^2 q3^2 ty^2-q2^2 q3^2 ty^2};
b={4 q0^6 q2^2 r2^2+8 q0^4 q1^2 q2^2 r2^2+4 q0^2 q1^4 q2^2 r2^2+8 q0^4 q2^4 r2^2+8 q0^2 q1^2 q2^4 r2^2+4 q0^2 q2^6 r2^2+8 q0^5 q1 q2 q3 r2^2+16 q0^3 q1^3 q2 q3 r2^2+8 q0 q1^5 q2 q3 r2^2+16 q0^3 q1 q2^3 q3 r2^2+16 q0 q1^3 q2^3 q3 r2^2+8 q0 q1 q2^5 q3 r2^2+4 q0^4 q1^2 q3^2 r2^2+8 q0^2 q1^4 q3^2 r2^2+4 q1^6 q3^2 r2^2+8 q0^4 q2^2 q3^2 r2^2+16 q0^2 q1^2 q2^2 q3^2 r2^2+8 q1^4 q2^2 q3^2 r2^2+8 q0^2 q2^4 q3^2 r2^2+4 q1^2 q2^4 q3^2 r2^2+16 q0^3 q1 q2 q3^3 r2^2+16 q0 q1^3 q2 q3^3 r2^2+16 q0 q1 q2^3 q3^3 r2^2+8 q0^2 q1^2 q3^4 r2^2+8 q1^4 q3^4 r2^2+4 q0^2 q2^2 q3^4 r2^2+8 q1^2 q2^2 q3^4 r2^2+8 q0 q1 q2 q3^5 r2^2+4 q1^2 q3^6 r2^2-4 q0^2 q1^2 ty^2-4 q0^2 q2^2 ty^2-4 q1^2 q3^2 ty^2-4 q2^2 q3^2 ty^2+4 q0^3 q1 ty tz-4 q0 q1^3 ty tz-4 q0 q1 q2^2 ty tz-4 q0^2 q2 q3 ty tz+4 q1^2 q2 q3 ty tz+4 q2^3 q3 ty tz+4 q0 q1 q3^2 ty tz-4 q2 q3^3 ty tz-q0^4 tz^2+2 q0^2 q1^2 tz^2-q1^4 tz^2-2 q0^2 q2^2 tz^2-2 q1^2 q2^2 tz^2-q2^4 tz^2-8 q0 q1 q2 q3 tz^2-2 q0^2 q3^2 tz^2-2 q1^2 q3^2 tz^2+2 q2^2 q3^2 tz^2-q3^4 tz^2,-16 q0^6 q1 q2 r2^2-32 q0^4 q1^3 q2 r2^2-16 q0^2 q1^5 q2 r2^2-32 q0^4 q1 q2^3 r2^2-32 q0^2 q1^3 q2^3 r2^2-16 q0^2 q1 q2^5 r2^2-16 q0^5 q1^2 q3 r2^2-32 q0^3 q1^4 q3 r2^2-16 q0 q1^6 q3 r2^2+16 q0^5 q2^2 q3 r2^2-16 q0 q1^4 q2^2 q3 r2^2+32 q0^3 q2^4 q3 r2^2+16 q0 q1^2 q2^4 q3 r2^2+16 q0 q2^6 q3 r2^2-16 q0^4 q1 q2 q3^2 r2^2+16 q1^5 q2 q3^2 r2^2+32 q1^3 q2^3 q3^2 r2^2+16 q1 q2^5 q3^2 r2^2-32 q0^3 q1^2 q3^3 r2^2-32 q0 q1^4 q3^3 r2^2+32 q0^3 q2^2 q3^3 r2^2+32 q0 q2^4 q3^3 r2^2+16 q0^2 q1 q2 q3^4 r2^2+32 q1^3 q2 q3^4 r2^2+32 q1 q2^3 q3^4 r2^2-16 q0 q1^2 q3^5 r2^2+16 q0 q2^2 q3^5 r2^2+16 q1 q2 q3^6 r2^2+16 q0^2 q1^2 tx ty+16 q0^2 q2^2 tx ty+16 q1^2 q3^2 tx ty+16 q2^2 q3^2 tx ty-8 q0^3 q1 tx tz+8 q0 q1^3 tx tz+8 q0 q1 q2^2 tx tz+8 q0^2 q2 q3 tx tz-8 q1^2 q2 q3 tx tz-8 q2^3 q3 tx tz-8 q0 q1 q3^2 tx tz+8 q2 q3^3 tx tz+8 q0^3 q2 ty tz-8 q0 q1^2 q2 ty tz-8 q0 q2^3 ty tz+8 q0^2 q1 q3 ty tz-8 q1^3 q3 ty tz-8 q1 q2^2 q3 ty tz+8 q0 q2 q3^2 ty tz+8 q1 q3^3 ty tz+16 q0^2 q1 q2 tz^2+16 q0 q1^2 q3 tz^2-16 q0 q2^2 q3 tz^2-16 q1 q2 q3^2 tz^2,16 q0^6 q1^2 r2^2+32 q0^4 q1^4 r2^2+16 q0^2 q1^6 r2^2-8 q0^6 q2^2 r2^2+16 q0^4 q1^2 q2^2 r2^2+24 q0^2 q1^4 q2^2 r2^2-16 q0^4 q2^4 r2^2-8 q0^2 q2^6 r2^2-48 q0^5 q1 q2 q3 r2^2-96 q0^3 q1^3 q2 q3 r2^2-48 q0 q1^5 q2 q3 r2^2-96 q0^3 q1 q2^3 q3 r2^2-96 q0 q1^3 q2^3 q3 r2^2-48 q0 q1 q2^5 q3 r2^2+24 q0^4 q1^2 q3^2 r2^2+16 q0^2 q1^4 q3^2 r2^2-8 q1^6 q3^2 r2^2+32 q0^2 q1^2 q2^2 q3^2 r2^2+16 q0^2 q2^4 q3^2 r2^2+24 q1^2 q2^4 q3^2 r2^2+16 q2^6 q3^2 r2^2-96 q0^3 q1 q2 q3^3 r2^2-96 q0 q1^3 q2 q3^3 r2^2-96 q0 q1 q2^3 q3^3 r2^2-16 q1^4 q3^4 r2^2+24 q0^2 q2^2 q3^4 r2^2+16 q1^2 q2^2 q3^4 r2^2+32 q2^4 q3^4 r2^2-48 q0 q1 q2 q3^5 r2^2-8 q1^2 q3^6 r2^2+16 q2^2 q3^6 r2^2-16 q0^2 q1^2 tx^2-16 q0^2 q2^2 tx^2-16 q1^2 q3^2 tx^2-16 q2^2 q3^2 tx^2+8 q0^2 q1^2 ty^2+8 q0^2 q2^2 ty^2+8 q1^2 q3^2 ty^2+8 q2^2 q3^2 ty^2-16 q0^3 q2 tx tz+16 q0 q1^2 q2 tx tz+16 q0 q2^3 tx tz-16 q0^2 q1 q3 tx tz+16 q1^3 q3 tx tz+16 q1 q2^2 q3 tx tz-16 q0 q2 q3^2 tx tz-16 q1 q3^3 tx tz-8 q0^3 q1 ty tz+8 q0 q1^3 ty tz+8 q0 q1 q2^2 ty tz+8 q0^2 q2 q3 ty tz-8 q1^2 q2 q3 ty tz-8 q2^3 q3 ty tz-8 q0 q1 q3^2 ty tz+8 q2 q3^3 ty tz-2 q0^4 tz^2-12 q0^2 q1^2 tz^2-2 q1^4 tz^2+12 q0^2 q2^2 tz^2-4 q1^2 q2^2 tz^2-2 q2^4 tz^2+48 q0 q1 q2 q3 tz^2-4 q0^2 q3^2 tz^2+12 q1^2 q3^2 tz^2-12 q2^2 q3^2 tz^2-2 q3^4 tz^2,16 q0^6 q1 q2 r2^2+32 q0^4 q1^3 q2 r2^2+16 q0^2 q1^5 q2 r2^2+32 q0^4 q1 q2^3 r2^2+32 q0^2 q1^3 q2^3 r2^2+16 q0^2 q1 q2^5 r2^2+16 q0^5 q1^2 q3 r2^2+32 q0^3 q1^4 q3 r2^2+16 q0 q1^6 q3 r2^2-16 q0^5 q2^2 q3 r2^2+16 q0 q1^4 q2^2 q3 r2^2-32 q0^3 q2^4 q3 r2^2-16 q0 q1^2 q2^4 q3 r2^2-16 q0 q2^6 q3 r2^2+16 q0^4 q1 q2 q3^2 r2^2-16 q1^5 q2 q3^2 r2^2-32 q1^3 q2^3 q3^2 r2^2-16 q1 q2^5 q3^2 r2^2+32 q0^3 q1^2 q3^3 r2^2+32 q0 q1^4 q3^3 r2^2-32 q0^3 q2^2 q3^3 r2^2-32 q0 q2^4 q3^3 r2^2-16 q0^2 q1 q2 q3^4 r2^2-32 q1^3 q2 q3^4 r2^2-32 q1 q2^3 q3^4 r2^2+16 q0 q1^2 q3^5 r2^2-16 q0 q2^2 q3^5 r2^2-16 q1 q2 q3^6 r2^2-16 q0^2 q1^2 tx ty-16 q0^2 q2^2 tx ty-16 q1^2 q3^2 tx ty-16 q2^2 q3^2 tx ty+8 q0^3 q1 tx tz-8 q0 q1^3 tx tz-8 q0 q1 q2^2 tx tz-8 q0^2 q2 q3 tx tz+8 q1^2 q2 q3 tx tz+8 q2^3 q3 tx tz+8 q0 q1 q3^2 tx tz-8 q2 q3^3 tx tz-8 q0^3 q2 ty tz+8 q0 q1^2 q2 ty tz+8 q0 q2^3 ty tz-8 q0^2 q1 q3 ty tz+8 q1^3 q3 ty tz+8 q1 q2^2 q3 ty tz-8 q0 q2 q3^2 ty tz-8 q1 q3^3 ty tz-16 q0^2 q1 q2 tz^2-16 q0 q1^2 q3 tz^2+16 q0 q2^2 q3 tz^2+16 q1 q2 q3^2 tz^2,4 q0^6 q2^2 r2^2+8 q0^4 q1^2 q2^2 r2^2+4 q0^2 q1^4 q2^2 r2^2+8 q0^4 q2^4 r2^2+8 q0^2 q1^2 q2^4 r2^2+4 q0^2 q2^6 r2^2+8 q0^5 q1 q2 q3 r2^2+16 q0^3 q1^3 q2 q3 r2^2+8 q0 q1^5 q2 q3 r2^2+16 q0^3 q1 q2^3 q3 r2^2+16 q0 q1^3 q2^3 q3 r2^2+8 q0 q1 q2^5 q3 r2^2+4 q0^4 q1^2 q3^2 r2^2+8 q0^2 q1^4 q3^2 r2^2+4 q1^6 q3^2 r2^2+8 q0^4 q2^2 q3^2 r2^2+16 q0^2 q1^2 q2^2 q3^2 r2^2+8 q1^4 q2^2 q3^2 r2^2+8 q0^2 q2^4 q3^2 r2^2+4 q1^2 q2^4 q3^2 r2^2+16 q0^3 q1 q2 q3^3 r2^2+16 q0 q1^3 q2 q3^3 r2^2+16 q0 q1 q2^3 q3^3 r2^2+8 q0^2 q1^2 q3^4 r2^2+8 q1^4 q3^4 r2^2+4 q0^2 q2^2 q3^4 r2^2+8 q1^2 q2^2 q3^4 r2^2+8 q0 q1 q2 q3^5 r2^2+4 q1^2 q3^6 r2^2-4 q0^2 q1^2 ty^2-4 q0^2 q2^2 ty^2-4 q1^2 q3^2 ty^2-4 q2^2 q3^2 ty^2+4 q0^3 q1 ty tz-4 q0 q1^3 ty tz-4 q0 q1 q2^2 ty tz-4 q0^2 q2 q3 ty tz+4 q1^2 q2 q3 ty tz+4 q2^3 q3 ty tz+4 q0 q1 q3^2 ty tz-4 q2 q3^3 ty tz-q0^4 tz^2+2 q0^2 q1^2 tz^2-q1^4 tz^2-2 q0^2 q2^2 tz^2-2 q1^2 q2^2 tz^2-q2^4 tz^2-8 q0 q1 q2 q3 tz^2-2 q0^2 q3^2 tz^2-2 q1^2 q3^2 tz^2+2 q2^2 q3^2 tz^2-q3^4 tz^2};
Print[a];
Print[b];
solk11=solvequartic[a,k1];
solk12=solvequartic[b,k1];
Return[Join[solk11,solk12]];

]


CD[r1_,l1_,r2_,l2_,q_,t_]:=
Module[{ft1,ft2,f\[Theta]1,f\[Theta]2,q0,q1,q2,q3,tx,k2,solk2,ty,tz,t1,t2,\[Theta]1,\[Theta]2,d,ret,mind,mini,solk1,ar3,ar,k1,nsolutions,ii,restol1,realsolns,tmp,p1,p2,sol\[Theta]1,sol\[Theta]2,sol\[Theta]12,sol\[Theta]22,sol\[Theta]21,sol\[Theta]11,solt2,solt1,polyk1,solt2s,solt1s,sol\[Theta]1s,sol\[Theta]2s},
Print["We are in CD now"];
Print[{r1,l1,r2,l2,q,t}];
{q0,q1,q2,q3}=q;
{tx,ty,tz}=t;
p1={r1 t1 Cos[\[Theta]1],r1 t1 Sin[\[Theta]1],0};
p2={tx+(q0^2+q1^2-q2^2-q3^2) r2 Cos[\[Theta]2]+(2 q1 q2-2 q0 q3) r2 Sin[\[Theta]2],ty+(2 q1 q2+2 q0 q3) r2 Cos[\[Theta]2]+(q0^2-q1^2+q2^2-q3^2) r2 Sin[\[Theta]2],tz+(-2 q0 q2+2 q1 q3) r2 Cos[\[Theta]2]+(2 q0 q1+2 q2 q3) r2 Sin[\[Theta]2]};

d=Norm[p1-p2];

solt1=cdsolt1f[\[Theta]1,\[Theta]2,t1,r1,l1,r2,l2,q,t];
solk2=cdsolk2f[k1,k2,r1,l1,r2,l2,q,t];
solk1=cdsolk1f[k1,r1,l1,r2,l2,q,t];

nsolutions=Array[0&,{Length[solk1],2}];
For[ii=1,ii<=Length[solk1],ii++,
Print["k1......"];
Print[k1/.solk1[[ii]]];
Print["k2......"];
Print[k2/.solk2/.solk1[[ii]]];
nsolutions[[ii]]=Flatten[{\[Theta]1->Chop[2 ArcTan[k1]/.solk1[[ii]]],\[Theta]2->Chop[2 ArcTan[k2]/.solk2/.solk1[[ii]]]}];
];

For[ii=1,ii<= Length[nsolutions],ii++,
Print["s=",t1/.solt1/.nsolutions[[ii]]];
nsolutions[[ii]]=Append[nsolutions[[ii]],solt1/.nsolutions[[ii]]];
nsolutions[[ii]]=Flatten[nsolutions[[ii]]];
];

(*filtering out real solutions*)
restol1=10^-3;
realsolns={};
For[ii=1,ii<= Length[nsolutions],ii++,
tmp={\[Theta]1,\[Theta]2,t1}/.nsolutions[[ii]];
If[Abs[Im[tmp]][[1]]<= restol1 && Abs[Im[tmp]][[2]]<= restol1 && Abs[Im[tmp]][[3]]<= restol1&& Re[tmp][[3]]>=0 ,realsolns=Append[realsolns,nsolutions[[ii]]]];
];


mind=d/.realsolns[[1]];
mini=1;
Print["t1=",t1/.realsolns[[1]],"     ","d=",d/.realsolns[[1]],"\[Theta]1=",\[Theta]1/.realsolns[[1]],"\[Theta]2=",\[Theta]2/.realsolns[[1]]];
For[ii=2,ii<= Length[realsolns],ii++,
Print["t1=",t1/.realsolns[[ii]],"     ","d=",d/.realsolns[[ii]],"\[Theta]1=",\[Theta]1/.realsolns[[ii]],"\[Theta]2=",\[Theta]2/.realsolns[[ii]]];
If[(d/.realsolns[[ii]])<mind,mind=(d/.realsolns[[ii]]);mini=ii];
];

If[Norm[(t1/.realsolns[[mini]])]>=  1,ft1=1;,ft1=(t1/.realsolns[[mini]]);];
f\[Theta]1=\[Theta]1/.realsolns[[mini]];
f\[Theta]2=\[Theta]2/.realsolns[[mini]];
ret={p1/.realsolns[[mini]],p2/.realsolns[[mini]],mind,{f\[Theta]1,f\[Theta]2,ft1}};
Return[ret];
]