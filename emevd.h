#pragma once

#include "common.h"
#include "aob.h"
#include "emedf.h"

namespace rts {

// This is extremely hacky and will segfault in many cases.
// A proper solution should replace it which allows execution in an actual event context.

int fakeVftableFunc() {
	return 0;
}
uint64_t fakeEventMan[16]{};
void* fakeVftable[18]{};

struct EventInsId {
	int bank;
	int id;
	void* unk10;
};

struct EventIns {
	void* vftable;
	void* unk08;
	uint8_t shortArgs[16];
	int* unkArgData;
	EventIns* prevIns;
	int eventId;
	int unk34;
	int eventId_;
	int unk3C;
	uint8_t unk40[0x30];
	int unk70;
	int unk74;
	int playerId;
	int unk7C;
	uint8_t unk80[0x50];
	// Note: when argData is null, id->unk10 and 0xC8 (and further pointers) are deferenced too.
	// 0xD0
	EventInsId* insId;
	uint8_t* argData;
	uint8_t unkE0[0xD0];
};
static_assert(sizeof(EventIns) == 0x1B0);

void callEmevd(int bank, int id, uint8_t* args, size_t argLength) {
	if (!fakeVftable[0]) {
		for (int i = 0; i < 18; i++) {
			fakeVftable[i] = fakeVftableFunc;
		}
	}
	EventIns ins{};
	EventInsId insId{};
	// This also calls vftable 9 (returns 0x120) expecting a byte enum >1, and checks 0xA8 (containing the event id and other things)
	// TODO make it work correctly.
	ins.vftable = fakeVftable;
	ins.playerId = 10000;
	insId.bank = bank;
	insId.id = id;
	ins.insId = &insId;
	if (argLength <= 16) {
		memcpy(ins.shortArgs, args, 16);
		// Setup so commands work. At the moment this is limited.
		ins.argData = ins.shortArgs;
	}
	else {
		ins.argData = args;
	}
	aob::emevdSwitch(fakeEventMan, nullptr, &ins);
}

template<typename T> void callEmevd(T args) {
	// TODO: Allocate long instructions correctly.
	// 36 is the longest in Elden Ring
	// Example invocation: rts::callEmevd(emedf::SetEventFlag{ 0, flag, true });
	static_assert(sizeof(T) <= 48);
	uint8_t argData[48]{};
	memcpy(argData, &args, sizeof(T));
	callEmevd(T::insBank, T::insId, argData, sizeof(T));
}

}