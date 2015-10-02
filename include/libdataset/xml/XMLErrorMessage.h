/**
 * Copyright - Benjamin Laugraud - 2015
 */
#ifndef _BGS_PLATFORM_LIBDATASET_XML_VALIDATORS_XML_ERROR_MESSAGE_H_
#define _BGS_PLATFORM_LIBDATASET_XML_VALIDATORS_XML_ERROR_MESSAGE_H_

#include <libxml/tree.h>

#include <string>

namespace BGS_Platform {
  namespace libdataset {
     class XMLErrorMessage {
       protected:

         int line;
         std::string file;
         std::string message;
         xmlNodePtr node;

       public:

         XMLErrorMessage(
           int line,
           const std::string& file,
           const std::string& message,
           xmlNodePtr node
         ) :
           line(line),
           file(file),
           message(message),
           node(node) {}

       public:

         int getLine() const;

         const std::string& getFile() const;

         const std::string& getMessage() const;

         xmlNodePtr getNode() const;

         std::string getFormattedMessage() const;
    };
  } /* _NS_libdataset_ */
} /* _NS_BGS_Platform_ */

#endif /* _BGS_PLATFORM_LIBDATASET_XML_VALIDATORS_XML_ERROR_MESSAGE_H_ */
