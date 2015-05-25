#ifndef TIGERWOODSUSERFILE_H
#define TIGERWOODSUSERFILE_H

#include <memory>

#include "IO/BaseIO.h"

class TigerWoodsUserFile
{
public:
    explicit TigerWoodsUserFile(std::shared_ptr<BaseIO> userFile);
};

#endif // TIGERWOODSUSERFILE_H
