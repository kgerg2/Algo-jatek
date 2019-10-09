Unit Gep;
Interface
  Function Kezd:longint;
  Function Mezo(i:longint; j:longint):longint;
  Procedure Lep(C:Char);
  Function GepLep:Char;
Implementation
Const
  MaxN=1000;            { max size of the board }
  Started:Boolean=False;
Type
  Tabla=Array[1..MaxN,1..MaxN] Of longint;
Var
  N,M: Word;           { a tabla merete }
  T:^Tabla;
  Pont:Longint;        { az elso jatekos altal elert osszpontszam }
  x,y:longint;         { a babu aktualis pozicioja }
  GLepes:Char;         { a gep utolso lepese }
  
Procedure Kiir(pont:longint; msg:string);
Begin
  writeln(msg);
  Dispose(T);
  halt;
end;

Procedure Beolv;
{ Global: N,M, T^ }
Var
  i,j,k,l:Word;
Begin
  ReadLn(N,M);
  For i:=1 To N Do
    For j:=1 To N Do
      T^[i,j]:=0;
  For l:=1 To M Do Begin
    ReadLn(i,j,k);
    T^[i,j]:=k;
  End;
End{Beolvas};

function Mezo(i:longint; j:longint):longint;
begin
	If Not Started Then Begin
      Kiir(0, 'hiba, a játékot a Kezd művelettel kell kezdeni');
    End;
    If (i<1) or (i>N) or (j<1) or (j>N) Then Begin
      Kiir(0, 'hiba, érvénytelen paraméter Mezo-ben');
    End;
	Mezo:=T^[i,j];
end;

Procedure Lep(C:Char);
  Begin
    If Not Started Then Begin
      Kiir(0, 'hiba, a játékot a Kezd művelettel kell kezdeni');
    End;
    If ((C<>'L') And (C<>'J')) Then Begin
      Kiir(0, 'hiba, érvénytelen paraméter Lep-ben');
    End;
    If C='L' Then  Begin
      Inc(x);
      If x>N Then
        Kiir(0, 'hiba, érvénytelen paraméter Lep-ben');
    End Else Begin
      Inc(y);
      If y>N Then
        Kiir(0, 'hiba, érvénytelen paraméter Lep-ben');
    End;
    Pont:=Pont+T^[x,y];
    {a 2. jatekos valaszlepese}
	if x=N then begin
		GLepes:='J';
		inc(y);
	end else begin
		GLepes:='L';
		inc(x);
	end;
    If (x=N) And (y=N) Then
		Kiir(1, 'helyes');
  End{Lep};

function GepLep():char;
  Begin
    If Not Started Then Begin
      Kiir(0, 'hiba, a játékot a Kezd művelettel kell kezdeni');
    End;
    GepLep:=GLepes;
  End;

function Kezd:longint;
{ Global: T,Pont, x,y }
Begin{Kezd}

  if Started then
	Kiir(0, 'hiba, Kezd-et csak egyszer szabad hívni');
  Started:=True;
  New(T);
  Beolv;
  Pont:=0;
  x:=1; y:=1;
  Kezd:=N;
End {Kezd};

Begin{Gep}

End{Gep}.
