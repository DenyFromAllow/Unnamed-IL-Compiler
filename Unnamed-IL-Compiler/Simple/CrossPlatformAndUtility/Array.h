#pragma once

enum class SIMPLE_TEMPLETEARRAY_LENGTH_CONTROL_MODE :uint8 {
	NoExtraLength,
	Shortest = NoExtraLength,

	UniformScale,
	Scale = UniformScale,
	Auto = UniformScale,
	DontCare = Auto,

	StaticExtraLength,
	ExtraLength = StaticExtraLength,

	LengthArray,
	StaticLength,
	Manual,

	Intelligence
};

template<typename ElementType>
class SIMPLE_TEMPLETEARRAY_AUTO {
private:
	ElementType *DataPointer = nullptr;
	uint64 MemLength = 0;
	uint64 Length = 0;
	uint32 ExtraLength = 50;
	SIMPLE_TEMPLETEARRAY_LENGTH_CONTROL_MODE LengthControlMode = SIMPLE_TEMPLETEARRAY_LENGTH_CONTROL_MODE::Auto;
public:
	const uint64 &length = Length;
	//void (*aaa)() = [=](int &a) { a++; return a; };

	SIMPLE_TEMPLETEARRAY_AUTO() { }

	explicit SIMPLE_TEMPLETEARRAY_AUTO(const ElementType* InPointer, const uint64 &InLength) : DataPointer(new ElementType[InLength]), MemLength(InLength), Length(InLength) {
		Simple_MemMovs(DataPointer, InPointer, InLength);
	}

	SIMPLE_TEMPLETEARRAY_AUTO(std::initializer_list<ElementType> InElement) : MemLength((int32) InElement.size()), Length(MemLength) {
		DataPointer = new ElementType[Length];
		Simple_MemMovs(DataPointer, InElement.begin(), Length);
	}

	SIMPLE_TEMPLETEARRAY_AUTO(const ElementType &InElement, const uint64 &InLength) : DataPointer(new ElementType[InLength]), MemLength(InLength), Length(InLength) {
		for(uint64 index = 0; index < Length; index++) {
			DataPointer[index] = InElement;
		}
	}

	explicit SIMPLE_TEMPLETEARRAY_AUTO(const uint64 &InLength) : DataPointer(new ElementType[InLength]), MemLength(InLength), Length(InLength) {
		for(uint64 index = 0; index < Length; index++) {
			DataPointer[index] = ElementType();
		}
	}

	SIMPLE_TEMPLETEARRAY_AUTO(const SIMPLE_TEMPLETEARRAY_AUTO& In) : DataPointer(new ElementType[In.Length]), MemLength(In.Length), Length(In.Length) {
		MemMovs(DataPointer, In.DataPointer, Length);
	}

	#if defined(_VECTOR_) || defined(_GLIBCXX_VECTOR)
	SIMPLE_TEMPLETEARRAY_AUTO(const std::vector<ElementType>& In) : DataPointer(new ElementType[In.size()]), MemLength(In.size()), Length(In.size()) {
		MemMovs<ElementType>(DataPointer, In.begin()._Ptr, Length);
	}
	#endif

	FORCEINLINE void clear() {
		MemLength = Length = 0;
		if(DataPointer == nullptr) {
			return;
		}
		delete[]DataPointer;
		DataPointer = nullptr;
	}

	~SIMPLE_TEMPLETEARRAY_AUTO() {
		clear();
	}

	FORCEINLINE bool check() {
		if(DataPointer == nullptr) {
			MemLength = Length = 0;
			return false;
		}
		if(MemLength == 0) {
			clear();
			return false;
		}
		return true;
	}

	bool fill(const ElementType &InElement) {
		if(!check())return false;
		for(uint64 index = 0; index < Length; index++) {
			DataPointer[index] = InElement;
		}
		return true;
	}

private:

	bool CreateArray(const uint64 &InLength, const uint64 &InMemLength) {
		clear();
		if(InLength > InMemLength)return false;
		Length = InLength;
		MemLength = InMemLength;
		DataPointer = new ElementType[InMemLength];
		return DataPointer != nullptr;
	}

	bool resize(const uint64 &InLength, const uint64 &InMemLength) {
		if(!check() || InLength > InMemLength)return false;
		ElementType *TempPointer = new ElementType[InMemLength];
		if(TempPointer == nullptr)return false;
		Simple_MemMovs(TempPointer, DataPointer, SimpleMath_Min2(InLength, Length));
		clear();
		Length = InLength;
		MemLength = InMemLength;
		DataPointer = TempPointer;
		return true;
	}

	bool CreateArray(const uint64 &InLength, const uint64 &InMemLength, const ElementType &FillElement) {
		clear();
		if(InLength > InMemLength)return false;
		Length = InLength;
		MemLength = InMemLength;
		DataPointer = new ElementType[InMemLength];
		if(DataPointer == nullptr)return false;
		fill(FillElement);
		return true;
	}

	bool resize(const uint64 &InLength, const uint64 &InMemLength, const ElementType &FillElement) {
		if(!check() || InLength > InMemLength)return false;
		ElementType *TempPointer = new ElementType[InMemLength];
		if(TempPointer == nullptr)return false;
		Simple_MemMovs(TempPointer, DataPointer, SimpleMath_Min2(InLength, Length));
		if(InLength > Length) {
			for(uint64 index = Length; index < InLength; index++) {
				TempPointer[index] = FillElement;
			}
		}
		clear();
		Length = InLength;
		MemLength = InMemLength;
		DataPointer = TempPointer;
		return true;
	}

	ElementType *ResizeAndGetOldData(const uint64 &InLength, const uint64 &InMemLength) {
		if(!check() || InLength > InMemLength)return nullptr;
		ElementType *TempPointer = DataPointer;
		DataPointer = new ElementType[InMemLength];
		if(DataPointer == nullptr)return nullptr;
		Length = InLength;
		MemLength = InMemLength;
		return TempPointer;
	}

	ElementType *LengthenAndGetOldData(const uint64 &InLength) {
		if(DataPointer == nullptr) {
			return nullptr;
		} else {
			if(MemLength == 0) {
				clear();
				return nullptr;
			}
			switch(LengthControlMode) {
				case SIMPLE_TEMPLETEARRAY_LENGTH_CONTROL_MODE::NoExtraLength:
					return ResizeAndGetOldData(InLength, InLength);
					break;
				case SIMPLE_TEMPLETEARRAY_LENGTH_CONTROL_MODE::StaticExtraLength:
					if(InLength + ExtraLength * 2 < MemLength) {
						return ResizeAndGetOldData(InLength, InLength);
					} else if(InLength <= MemLength) {
						return ResizeAndGetOldData(InLength, MemLength);
					} else {
						return ResizeAndGetOldData(InLength, (InLength > MemLength + ExtraLength) ? InLength : MemLength + ExtraLength);
					}
					break;
				case SIMPLE_TEMPLETEARRAY_LENGTH_CONTROL_MODE::UniformScale:
				default:
					if(InLength + InLength * ExtraLength / 50 < MemLength) {
						return ResizeAndGetOldData(InLength, InLength);
					} else if(InLength <= MemLength) {
						return ResizeAndGetOldData(InLength, MemLength);
					} else {
						return ResizeAndGetOldData(InLength, (InLength > MemLength + MemLength * ExtraLength / 100) ? InLength : MemLength + MemLength * ExtraLength / 100);
					}
					break;
			}
		}
		return nullptr;
	}

public:
	bool CreateArray(const uint64 &InLength, const ElementType &FillElement) {
		clear();
		Length = MemLength = InLength;
		DataPointer = new ElementType[InLength];
		if(DataPointer == nullptr)return false;
		fill(FillElement);
		return true;
	}

	bool LengthenAndFill(const uint64 &InLength, const ElementType &FillElement) {
		if(DataPointer == nullptr) {
			return CreateArray(InLength, InLength, FillElement);
		} else {
			if(MemLength == 0) {
				clear();
				return CreateArray(InLength, InLength, FillElement);
			}
			switch(LengthControlMode) {
				case SIMPLE_TEMPLETEARRAY_LENGTH_CONTROL_MODE::NoExtraLength:
					return CreateArray(InLength, InLength, FillElement);
					break;
				case SIMPLE_TEMPLETEARRAY_LENGTH_CONTROL_MODE::StaticExtraLength:
					if(InLength + ExtraLength * 2 < MemLength) {
						return CreateArray(InLength, InLength, FillElement);
					} else if(InLength <= MemLength) {
						Length = InLength;
						fill(FillElement);
					} else {
						return CreateArray(InLength, (InLength > MemLength + ExtraLength) ? InLength : MemLength + ExtraLength, FillElement);
					}
					break;
				case SIMPLE_TEMPLETEARRAY_LENGTH_CONTROL_MODE::UniformScale:
				default:
					if(InLength + InLength * ExtraLength / 50 < MemLength) {
						return CreateArray(InLength, InLength, FillElement);
					} else if(InLength <= MemLength) {
						Length = InLength;
						fill(FillElement);
					} else {
						return CreateArray(InLength, (InLength > MemLength + MemLength * ExtraLength / 100) ? InLength : MemLength + MemLength * ExtraLength / 100, FillElement);
					}
					break;
			}
		}
		return true;
	}

	bool Lengthen(const uint64 &InLength, const ElementType &FillElement) {
		if(DataPointer == nullptr) {
			return CreateArray(InLength, InLength, FillElement);
		} else {
			if(MemLength == 0) {
				clear();
				return CreateArray(InLength, InLength, FillElement);
			}
			switch(LengthControlMode) {
				case SIMPLE_TEMPLETEARRAY_LENGTH_CONTROL_MODE::NoExtraLength:
					return resize(InLength, InLength, FillElement);
					break;
				case SIMPLE_TEMPLETEARRAY_LENGTH_CONTROL_MODE::StaticExtraLength:
					if(InLength + ExtraLength * 2 < MemLength) {
						return resize(InLength, InLength, FillElement);
					} else if(InLength <= MemLength) {
						for(uint64 index = Length; index < InLength; index++) {
							DataPointer[index] = FillElement;
						}
						Length = InLength;
					} else {
						return resize(InLength, (InLength > MemLength + ExtraLength) ? InLength : MemLength + ExtraLength, FillElement);
					}
					break;
				case SIMPLE_TEMPLETEARRAY_LENGTH_CONTROL_MODE::UniformScale:
				default:
					if(InLength + InLength * ExtraLength / 50 < MemLength) {
						return resize(InLength, InLength, FillElement);
					} else if(InLength <= MemLength) {
						for(uint64 index = Length; index < InLength; index++) {
							DataPointer[index] = FillElement;
						}
						Length = InLength;
					} else {
						return resize(InLength, (InLength > MemLength + MemLength * ExtraLength / 100) ? InLength : MemLength + MemLength * ExtraLength / 100, FillElement);
					}
					break;
			}
		}
		return true;
	}

	bool fill(const ElementType &InElement, const int32 &last) {
		if(!check())return CreateArray(last, last, InElement);
		if(last > Length) {
			return LengthenAndFill(last, InElement);
		}
		for(uint64 index = 0; index < last; index++) {
			DataPointer[index] = InElement;
		}
		return true;
	}

	bool fill(const ElementType &InElement, const int32 &first, const int32 &last) {
		if(first <= last) {
			return false;
		}
		if(!check())if(!CreateArray(last, last, InElement))return false;
		if(last > Length) {
			if(!Lengthen(last, InElement))return false;
		}
		for(uint64 index = first; index < last; index++) {
			DataPointer[index] = InElement;
		}
		return true;
	}

	bool PushBack(const ElementType &InElement) {
		if(!DataPointer || !MemLength) {
			if(CreateArray(1, 1, InElement)) {
				return true;
			} else {
				return false;
			}
		} else if(Length < MemLength) {
			DataPointer[Length++] = InElement;
		} else {
			Lengthen(Length + 1, InElement);
		}
		return true;
	}

	FORCEINLINE bool operator<(const ElementType &InElement) {
		return PushBack(InElement);
	}

	bool PushBack(const SIMPLE_TEMPLETEARRAY_AUTO<ElementType> &InArray) {
		if(!check()) {
			if(!CreateArray(InArray.Length, InArray.Length))return false;
			Simple_MemMovs(DataPointer, InArray.DataPointer, InArray.Length);
		} else {
			uint64 OldLength = Length, InLength = InArray.Length;
			Lengthen(Length + InArray.Length, ElementType());
			Simple_MemMovs(DataPointer + OldLength, InArray.DataPointer, InLength);
		}
		return true;
	}

	FORCEINLINE bool operator<<(const SIMPLE_TEMPLETEARRAY_AUTO<ElementType> &InArray) {
		return PushBack(InArray);
	}

	#if defined(_VECTOR_) || defined(_GLIBCXX_VECTOR)
	bool PushBack(const std::vector<ElementType> &InVector) {
		if(!check()) {
			if(!CreateArray(InVector.size(), InVector.size()))return false;
			MemMovs(DataPointer, InVector.begin()._Ptr, InVector.size());
		} else {
			uint64 OldLength = Length;
			Lengthen(Length + InVector.size(), ElementType());
			MemMovs(DataPointer + OldLength, InVector.begin()._Ptr, InVector.size());
		}
		return true;
	}

	FORCEINLINE bool operator<<(const std::vector<ElementType> &InVector) {
		return PushBack(InVector);
	}
	#endif

	ElementType &operator[](uint64 index) {
		if(index >= Length)Lengthen(index + 1, ElementType());
		return DataPointer[index];
	}
};

#if defined(_IOSTREAM_) || defined(_GLIBCXX_IOSTREAM)
template <typename ElementType>
std::ostream& operator<<(std::ostream& stream, SIMPLE_TEMPLETEARRAY_AUTO<ElementType> &Array) {
	if(Array.length == 0)return stream;
	stream << Array[0];
	for(uint64 i = 1; i < Array.length; i++) {
		stream << ',' << Array[i];
	}
	return stream;
}
#endif

template<typename ElementType>
class SIMPLE_TEMPLETEARRAY_MANUAL {

};