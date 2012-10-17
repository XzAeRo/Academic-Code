/* Funcion objetivo */
min: 4 XV + 3 I + 2 II + 5 III + 7 IV + 6 V + 8 RM + 7 VI + 8 VII + 7 VIII + 9 IX + 9 X + 10 XI + 11 XII + 4 XIII + 7 XIV + 2 C15 + 2 C1 + 2 C2 + 2 C3 + 2 C4 + 2 C5 + 2 CRM + 2 C6 + 2 C7 + 2 C8 + 2 C9 + 2 C10 + 2 C11 + 2 C12 + 2 C13 + 2 C14;

/* Restricciones de demanda */
1800 XV + 1800 I + 400 C15 + 400 C1 + 400 C2 >= 650 ;				/* XV Region*/
1800 XV + 1800 I + II 1800 + 400 C15 + 400 C1 + 400 C2 >= 650;		/* I Region */
1800 I + 1800 II  + 1800 III + 400 C1 + 400 C2 + 400 C3 >= 700;		/* II Region */
1800 II + 1800 III + 1800 IV + 400 C2 + 400 C3 + 400 C4 >= 800;		/* III Region */
1800 III + 1800 IV + 1800 V + 400 C3 + 400 C4 + 400 C5 >= 400;		/* IV Region */
1800 IV + 1800 V + 1800 RM + 400 C4 + 400 C5 + 400 CRM >= 950;		/* V Region */
1800 V + 1800 RM + 1800 VI + 400 C5 + 400 CRM + 400 C6 >= 1200;		/* Region Metropolitana*/
1800 RM + 1800 VI + 1800 VII + 400 CRM + 400 C6 + 400 C7 >= 600;	/* VI Region */
1800 VI + 1800 VII + 1800 VIII + 400 C6 + 400 C7 + 400 C8 >= 400;	/* VII Region */
1800 VII + 1800 VIII + 1800 IX + 400 C7 + 400 C8 + 400 C9 >= 700;	/* VIII Region */
1800 VIII + 1800 IX + 1800 X + 400 C8 + 400 C9 + 400 C10 >= 450;	/* IX Region */
1800 IX + 1800 X + 1800 XI + 400 C9 + 400 C10 + 400 C11 >= 400;		/* X Region */
1800 X + 1800 XI + 1800 XII + 400 C10 + 400 C11 + 400 C12 >= 350;	/* XI Region */
1800 XI + 1800 XII + 1800 XIII + 400 C11 + 400 C12 + 400 C13 >= 350;/* XII Region */
1800 XII + 1800 XIII + 1800 XIV + 400 C12 + 400 C13 + 400 C14 >= 300;/* XIII Region */
1800 XIII + 1800 XIV + 400 C13 + 400 C14 >= 250;					/* XIV Region */

/* Restricciones de distancia (al menos 1 central cada 2 regiones) */
XV + I >= 1;
II + III >= 1;
IV + V >= 1;
RM + VI >= 1;
VII + VIII >= 1;
IX + X >= 1;
XI + XII >= 1;
XIII + XIV >= 1;

/* Restricciones de costo: no se pueden usar enlaces adicionales si no se ha instalado central */
C1 <= I;
C2 <= II;
C3 <= III;
C4 <= IV;
C5 <= V;
C6 <= VI;
C7 <= VII;
C8 <= VIII;
C9 <= IX;
C10 <= X;
C11 <= XI;
C12 <= XII;
C13 <= XIII;
C14 <= XIV;
C15 <= XV;
CRM <= RM;

/* Restriccion if-else: si se hace una central en RM no se puede construir en V o VI */
/* Si RM > 0 entonces V = VII = 0 */
V + VI <= Y;
RM <= 1 - Y;

/* Naturaleza de las variables */
bin I, II, III, IV, V, VI, VII, VIII, IX, X, XI, XII, XIII, XIV, XV, RM, Y, C1, C2, C3, C4, C5, C6, C7, C8, C9, C10, C11, C12, C13, C14, C15, CRM, Y;
