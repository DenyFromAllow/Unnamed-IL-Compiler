#pragma once

struct Label {
	String name;
	uint32 AddressID;
	uint32 Pointer; //地址id或函数内地址
};

struct TempVariable {
	uint8 Flags;//Low->High bit0~bit1 0=Endless 1=UntilLable 2=InstructionCount 3=#Line bit7(Highest): IsValid Valid when flags not zero.
	uint8 ID;
	String Name;
	String EndLableName;
	uint32 End;//#Instruction in function
};

struct ReserveSharedTempVariable {
	uint8 Flags;//Low->High bit0~bit1 0=Endless 1=UntilLable 2=InstructionCount 3=#Line bit7(Highest): IsValid Valid when flags not zero.
	uint8 ID;
	uint32 LabelID;
	String Name;
	String EndLableName;
	uint32 End;//#Instruction in function
};

struct Block {
	enum class Type :uint8 {
		Function,
		Class,
		Struct,
		Enum,
		Parameters,
		ReturnValues
	};
	Type BlockType;
	void *Entity;
	Block *prev;
};

struct MemAllocation {
	uint32 AddressID;
	uint32 Flags;
	uint32 ElementCount;
	ILCArray<uint8> XFlags;
	ILCArray<uint8> data;
	String Name;
	bool IsPtr;
	bool PtrInitZero;
};

struct MemberVarDefinition {
	uint32 Flags;
	uint32 ElementCount;
	ILCArray<uint8> XFlags;
	String Name;
	bool IsPtr;
};

struct ExportDefinition {
	uint32 AddressID;
	String Name;
};

struct MemberProcDefinition {
	uint32 AddressID;
	String Name;
	String OldName;
};

struct ParameterDefinition {
	uint32 AddressID;
	uint32 ElementCount;
	bool isTemp;
	enum class Type :uint8 {
		Normal,
		ptr
	};
	uint8 ParameterType;//ParameterDefinition::Type, or VarType in temp parameter.
	bool HasDefault;
	bool IsSx;//sx or zx
	ILCArray<uint8> Default;
};

struct ReturnValueDefinition {
	uint32 ElementCount;
	enum class definitionType :uint8 {
		stack,
		ptr,
		temp
	}DefinitionType;
	uint8 Type;
	bool IsSx;//sx or zx
};

struct EnumDefinition {
	uint8 BaseType;
	uint32 Flags;
	uint32 TypeID;
	ILCArray<uint8> XFlags;
	ILCArray<uint8> ItemNames;
	ILCArray<String> ItemValues;
	String Name;
};

struct StructDefinition {
	uint32 Flags;
	uint32 TypeID;
	ILCArray<uint8> XFlags;
	ILCArray<MemberVarDefinition> Members;
	String Name;
};

struct ConstructorDefinition {
	uint32 AddressID;
	ILCArray<ParameterDefinition> Parameters;
	ILCArray<MemAllocation> StackVariables;
	uint32 Flags;
	String Name;
	ILCArray<uint8> Instructions;
};

struct ClassDefinition {
	uint32 BaseType;
	uint32 Flags;
	uint32 TypeID;
	ILCArray<uint8> XFlags;
	ILCArray<ConstructorDefinition> Constructors;
	ILCArray<MemberVarDefinition> MemberVariables;
	ILCArray<MemberProcDefinition>  MemberProcesses;
	ILCArray<EnumDefinition>  InnerEnums;
	ILCArray<StructDefinition>  InnerStructs;
	ILCArray<ClassDefinition>  InnerClasses;
	String Name;
};

struct ExceptionHandler {
	uint32 Flags;
	ILCArray<MemAllocation> StackVariables;
	ILCArray<uint8> XFlags;
	ILCArray<uint8> Instructions;
};

struct AppendedFunction {
	uint32 AddressID;
	uint32 Flags;
	ILCArray<ParameterDefinition> Parameters;
	ILCArray<ReturnValueDefinition> ReturnValues;
	ILCArray<MemAllocation> StackVariables;
	ILCArray<uint8> XFlags;
	String Name;
	ILCArray<uint8> Instructions;
};

struct FunctionDefinition {
	uint32 AddressID;
	uint32 Flags;
	ILCArray<ParameterDefinition> Parameters;
	ILCArray<ReturnValueDefinition> ReturnValues;
	ILCArray<MemAllocation> StackVariables;
	ILCArray<AppendedFunction> AppendedFunctions;
	ILCArray<ExceptionHandler> ExceptionHandlers;
	ILCArray<uint8> XFlags;
	String Name;
	ILCArray<uint8> Instructions;
};