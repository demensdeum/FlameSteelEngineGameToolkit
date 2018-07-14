#ifndef FSEGTSERIALIZEDMODELDEFINED
#define FSEGTSERIALIZEDMODELDEFINED

#include <FlameSteelCore/Object.h>

using namespace FlameSteelCore;

class FSEGTSerializedModel: public Object {

public:

	FSEGTSerializedModel(shared_ptr<string> serializedModel);

	shared_ptr<string> serializedModel;

};

#endif