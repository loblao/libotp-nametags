/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file config_nametag.h
 * @author loblao
 */

#ifndef CONFIG_NAMETAG_H
#define CONFIG_NAMETAG_H

#include "pandabase.h"
#include "notifyCategoryProxy.h"
#include "configVariableString.h"

// XXX this usually goes in pandasymbols.h
#ifdef BUILDING_PANDA
  #define EXPCL_NAMETAG EXPORT_CLASS
  #define EXPTP_NAMETAG EXPORT_TEMPL
#else
  #define EXPCL_NAMETAG IMPORT_CLASS
  #define EXPTP_NAMETAG IMPORT_TEMPL
#endif

#define NAMETAG_REFCOUNT_HACK \
  INLINE virtual int get_ref_count() const final { return ReferenceCount::get_ref_count(); }; \
  INLINE virtual void ref() const final { ReferenceCount::ref(); }; \
  INLINE virtual bool unref() const final { return ReferenceCount::unref(); };

BEGIN_PUBLISH

enum ChatFlags {
  CF_speech = 1,
  CF_thought = 2,
  CF_quicktalker = 4,
  CF_timeout = 8,
  CF_page_button = 16,
  CF_quit_button = 32,
  CF_reversed = 64,
  CF_snd_openchat = 128,
  CF_no_quit_button = 256
};

END_PUBLISH

NotifyCategoryDecl(nametag, EXPCL_NAMETAG, EXPTP_NAMETAG);

extern ConfigVariableString nametag_fixed_bin;

extern EXPCL_NAMETAG void init_libnametag();

#endif // CONFIG_NAMETAG_H
