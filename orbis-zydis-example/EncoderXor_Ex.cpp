#include "stdafx.h"

ZyanStatus EncoderXor_Ex()
{
	ZydisEncoderRequest encReq{};

	encReq.mnemonic = ZYDIS_MNEMONIC_XOR;
	encReq.machine_mode = ZYDIS_MACHINE_MODE_LONG_64;
	encReq.operand_count = 2;

	encReq.operands[0].type = ZYDIS_OPERAND_TYPE_REGISTER;
	encReq.operands[0].reg.value = ZYDIS_REGISTER_RAX;

	encReq.operands[1].type = ZYDIS_OPERAND_TYPE_REGISTER;
	encReq.operands[1].reg.value = ZYDIS_REGISTER_RAX;

	ZyanU8 encInstr[ZYDIS_MAX_INSTRUCTION_LENGTH];
	ZyanUSize encInstrLen = sizeof(encInstr);
	if (ZYAN_FAILED(ZydisEncoderEncodeInstruction(&encReq, encInstr, &encInstrLen)))
	{
		return ZYAN_STATUS_FAILED;
	}

	for (ZyanUSize i = 0; i < encInstrLen; ++i)
	{
		printf("%02X ", encInstr[i]);
	}
	
	return ZYAN_STATUS_SUCCESS;
}