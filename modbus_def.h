
struct Modbus_s {
	
};

enum FunctionCode_e {
	ReadDiscreteInputs = 0x02,
	ReadCoils = 0x01,
	WriteSingleCoil = 0x05,
	WriteMultipleCoils = 0x0F,
	ReadInputRegister = 0x04,
	ReadHoldingRegisters = 0x03,
	WriteSingleRegister = 0x06,
	WriteMultipleRegisters = 0x10,
	ReadWriteMultipleRegisters = 0x17
	/* Not Yet Implemented
	MaskWriteRegister = 0x16,
	ReadFIFOQueue = 0x18,
	ReadFileRecord = 0x14,
	WriteFileRecord = 0x15,
	ReadExceptionStatus = 0x07,
	Diagnostic = 0x08,
	GetComEventCounter = 0x0B,
	GetComEventLog = 0x0C,
	ReportServerID = 0x11,
	ReadDeviceIdentification 0x2B 
	*/
};

enum Behaviour_e {
	BEHAVIOUR_FC_NOT_SUPPORTED,
	BEHAVIOUR_EXEC_CALLBACK_FUNCTION,
	BEHAVIOUR_USE_MEMORY_MAPPING
};

struct MemoryMapping_s {

}

struct AssociatedBehaviour_s {
	enum FunctionCode_e functionCode;
	enum Behaviour_e behaviour;
	union {
		void (* callBackFunction) ( enum FunctionCode_e, unsigned char* data, int datalen );
		struct MemoryMapping_s * memorySegment;
	}
}
