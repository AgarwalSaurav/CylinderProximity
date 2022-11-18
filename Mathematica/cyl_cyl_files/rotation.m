(* ::Package:: *)

skew2axis[\[CapitalOmega]_] := Module[{},
      
      Return[{\[CapitalOmega][[3, 2]], \[CapitalOmega][[1, 3]], \[CapitalOmega][[2, 1]]}];
      ];


r2q[R_] :=
Module[{tr,x,y,z, q0,q1, q2, q3}, 
 tr =  (Tr[R]); 
q0=Sqrt[(tr +1)/4];
x=(R[[3,2]]-R[[2,3]])/4;
y=(R[[1,3]]-R[[3,1]])/4;
z=(R[[2,1]]-R[[1,2]])/4;
If[q0==0,(
q1=Sqrt[(R[[1,1]]+1)/2];
If[q1==0,(q2=Sqrt[(R[[2,2]]+1)/2];If[q2==0,q3=1,q3=R[[2,3]]/(2 q2)]),
q2=R[[1,2]]/(2 q1);
q3=R[[1,3]]/(2 q1);]
),q1=x/q0;
q2=y/q0;
q3=z/q0;];
 Return[{q0,q1,q2,q3}];
];


q2r[q_]:=Module[{q0,q1,q2,q3,R},
{q0,q1,q2,q3}=q;
R = {{q0^2+q1^2-q2^2-q3^2,2 q1 q2-2 q0 q3,2 q1 q3+2 q0 q2},{2 q1 q2+2 q0 q3,q0^2-q1^2+q2^2-q3^2,2 q2 q3-2q0 q1},{2 q1 q3-2 q0 q2,2q2 q3+2 q0 q1, q0^2-q1^2-q2^2+q3^2}};
Return[R];
]
