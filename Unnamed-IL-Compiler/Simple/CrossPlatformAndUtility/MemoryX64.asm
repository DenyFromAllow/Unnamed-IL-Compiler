.CODE

InSrc     EQU       R8
InDst     EQU       RDX
Src       EQU       RSI
Dst       EQU       RDI

;InCount = Count = RCX
?Simple_MemMovsb@@YAX_KPEBX1@Z PROC
	PUSH      Src
	PUSH      Dst
	
	MOV       Src,                InSrc
	MOV       Dst,                InDst
	REP MOVSB
	
	POP       Dst
	POP       Src
	RET
?Simple_MemMovsb@@YAX_KPEBX1@Z ENDP

?Simple_MemMovsw@@YAX_KPEBX1@Z PROC
	PUSH      Src
	PUSH      Dst
	
	MOV       Src,                InSrc
	MOV       Dst,                InDst
	REP MOVSW
	
	POP       Dst
	POP       Src
	RET
?Simple_MemMovsw@@YAX_KPEBX1@Z ENDP

?Simple_MemMovsd@@YAX_KPEBX1@Z PROC
	PUSH      Src
	PUSH      Dst
	
	MOV       Src,                InSrc
	MOV       Dst,                InDst
	REP MOVSD
	
	POP       Dst
	POP       Src
	RET
?Simple_MemMovsd@@YAX_KPEBX1@Z ENDP

?Simple_MemMovsq@@YAX_KPEBX1@Z PROC
	PUSH      Src
	PUSH      Dst
	
	MOV       Src,                InSrc
	MOV       Dst,                InDst
	REP MOVSQ
	
	POP       Dst
	POP       Src
	RET
?Simple_MemMovsq@@YAX_KPEBX1@Z ENDP

?Simple_MemFindb@@YA_KPEBXE@Z PROC
	MOV       RAX,                RCX
	JMP       FindFirst
	
	FindNext:
	ADD       RAX,                1
	
	FindFirst:
	CMP       DL,                 BYTE PTR[RAX]
	JNE       FindNext
	
	SUB       RAX,                RCX
	
	RET
?Simple_MemFindb@@YA_KPEBXE@Z ENDP

?Simple_MemFindw@@YA_KPEBXG@Z PROC
	MOV       RAX,                RCX
	JMP       FindFirst
	
	FindNext:
	ADD       RAX,                2
	
	FindFirst:
	CMP       DX,                 WORD PTR[RAX]
	JNE       FindNext
	
	SUB       RAX,                RCX
	SHR       RAX,                1
	
	RET
?Simple_MemFindw@@YA_KPEBXG@Z ENDP

?Simple_MemFindd@@YA_KPEBXK@Z PROC
	MOV       RAX,                RCX
	JMP       FindFirst
	
	FindNext:
	ADD       RAX,                4
	
	FindFirst:
	CMP       EDX,                DWORD PTR[RAX]
	JNE       FindNext
	
	SUB       RAX,                RCX
	SHR       RAX,                2
	
	RET
?Simple_MemFindd@@YA_KPEBXK@Z ENDP

?Simple_MemFindq@@YA_KPEBX_K@Z PROC
	MOV       RAX,                RCX
	JMP       FindFirst
	
	FindNext:
	ADD       RAX,                8
	
	FindFirst:
	CMP       RDX,                QWORD PTR[RAX]
	JNE       FindNext
	
	SUB       RAX,                RCX
	SHR       RAX,                3
	
	RET
?Simple_MemFindq@@YA_KPEBX_K@Z ENDP


?Simple_MemMoveHighb@@YAXPEBX_K1@Z PROC
	ADD			RDX,					RCX
	SUB			RDX,					1
	ADD			R8,						RDX
	
	Move:
	MOV			AL,						BYTE PTR[RDX]
	MOV			BYTE PTR[R8],			AL
	SUB			RDX,					1
	SUB			R8,						1
	CMP			RDX,					RCX
	JAE			Move
	
	RET
?Simple_MemMoveHighb@@YAXPEBX_K1@Z ENDP

?Simple_MemMoveHighw@@YAXPEBX_K1@Z PROC
	SHL			RDX,					1
	SHL			R8,						1
	ADD			RDX,					RCX
	SUB			RDX,					2
	ADD			R8,						RDX
	
	Move:
	MOV			AX,						WORD PTR[RDX]
	MOV			WORD PTR[R8],			AX
	SUB			RDX,					2
	SUB			R8,						2
	CMP			RDX,					RCX
	JAE			Move
	
	RET
?Simple_MemMoveHighw@@YAXPEBX_K1@Z ENDP

?Simple_MemMoveHighd@@YAXPEBX_K1@Z PROC
	SHL			RDX,					2
	SHL			R8,						2
	ADD			RDX,					RCX
	SUB			RDX,					4
	ADD			R8,						RDX
	
	Move:
	MOV			EAX,					DWORD PTR[RDX]
	MOV			DWORD PTR[R8],			EAX
	SUB			RDX,					4
	SUB			R8,						4
	CMP			RDX,					RCX
	JAE			Move
	
	RET
?Simple_MemMoveHighd@@YAXPEBX_K1@Z ENDP

?Simple_MemMoveHighq@@YAXPEBX_K1@Z PROC
	SHL			RDX,					3
	SHL			R8,						3
	ADD			RDX,					RCX
	SUB			RDX,					8
	ADD			R8,						RDX
	
	Move:
	MOV			RAX,					QWORD PTR[RDX]
	MOV			QWORD PTR[R8],			RAX
	SUB			RDX,					8
	SUB			R8,						8
	CMP			RDX,					RCX
	JAE			Move
	
	RET
?Simple_MemMoveHighq@@YAXPEBX_K1@Z ENDP

?Simple_MemMoveLowb@@YAXPEBX_K1@Z PROC
	ADD			RDX,					RCX
	MOV			RAX,					R8
	MOV			R8,						RCX
	SUB			R8,						RAX
	
	Move:
	MOV			AL,						BYTE PTR[RCX]
	MOV			BYTE PTR[R8],			AL
	ADD			RCX,					1
	ADD			R8,						1
	CMP			RCX,					RDX
	JB			Move
	
	RET
?Simple_MemMoveLowb@@YAXPEBX_K1@Z ENDP

?Simple_MemMoveLoww@@YAXPEBX_K1@Z PROC
	SHL			RDX,					1
	SHL			R8,						1
	ADD			RDX,					RCX
	MOV			RAX,					R8
	MOV			R8,						RCX
	SUB			R8,						RAX
	
	Move:
	MOV			AX,						WORD PTR[RCX]
	MOV			WORD PTR[R8],			AX
	ADD			RCX,					2
	ADD			R8,						2
	CMP			RCX,					RDX
	JB			Move
	
	RET
?Simple_MemMoveLoww@@YAXPEBX_K1@Z ENDP

?Simple_MemMoveLowd@@YAXPEBX_K1@Z PROC
	SHL			RDX,					2
	SHL			R8,						2
	ADD			RDX,					RCX
	MOV			RAX,					R8
	MOV			R8,						RCX
	SUB			R8,						RAX
	
	Move:
	MOV			EAX,					DWORD PTR[RCX]
	MOV			DWORD PTR[R8],			EAX
	ADD			RCX,					4
	ADD			R8,						4
	CMP			RCX,					RDX
	JB			Move
	
	RET
?Simple_MemMoveLowd@@YAXPEBX_K1@Z ENDP

?Simple_MemMoveLowq@@YAXPEBX_K1@Z PROC
	SHL			RDX,					3
	SHL			R8,						3
	ADD			RDX,					RCX
	MOV			RAX,					R8
	MOV			R8,						RCX
	SUB			R8,						RAX
	
	Move:
	MOV			RAX,					QWORD PTR[RCX]
	MOV			QWORD PTR[R8],			RAX
	ADD			RCX,					8
	ADD			R8,						8
	CMP			RCX,					RDX
	JB			Move
	
	RET
?Simple_MemMoveLowq@@YAXPEBX_K1@Z ENDP

END
