# -*- makefile -*-
#----------------------------------------------------------------------------
#       GNU ACE Workspace
#
# $Id: GNUACEWorkspaceCreator.pm 94635 2011-10-06 12:59:23Z johnnyw $
#
# This file was generated by MPC.  Any changes made directly to
# this file will be lost the next time it is generated.
#
# MPC Command:
# /home/build/DOC_ROOT/stage-644/ACE_wrappers/bin/mwc.pl -type gnuace -exclude "TAO/TAO_*.mwc,TAO/CIAO/CIAO_*.mwc" -workers 10 -recurse -hierarchy -relative ACE_ROOT=/home/build/DOC_ROOT/stage-644/ACE_wrappers -relative TAO_ROOT=/home/build/DOC_ROOT/stage-644/ACE_wrappers/TAO -relative CIAO_ROOT=/home/build/DOC_ROOT/stage-644/ACE_wrappers/TAO/CIAO -relative DANCE_ROOT=/home/build/DOC_ROOT/stage-644/ACE_wrappers/TAO/DAnCE
#
#----------------------------------------------------------------------------

MAKEFILE = GNUmakefile

ifeq ($(findstring k,$(MAKEFLAGS)),k)
  KEEP_GOING = -
endif

include $(ACE_ROOT)/include/makeinclude/macros.GNU

all: OfferSubscriptions_Idl OfferSubscriptions_Consumer OfferSubscriptions_Client OfferSubscriptions_Server

REMAINING_TARGETS := $(filter-out all,$(TARGETS_NESTED:.nested=)) $(CUSTOM_TARGETS)

$(REMAINING_TARGETS):
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.OfferSubscriptions_Idl $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.OfferSubscriptions_Consumer $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.OfferSubscriptions_Client $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.OfferSubscriptions_Server $(@)

.PHONY: OfferSubscriptions_Idl
OfferSubscriptions_Idl:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.OfferSubscriptions_Idl all

.PHONY: OfferSubscriptions_Consumer
OfferSubscriptions_Consumer: OfferSubscriptions_Idl
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.OfferSubscriptions_Consumer all

.PHONY: OfferSubscriptions_Client
OfferSubscriptions_Client: OfferSubscriptions_Idl OfferSubscriptions_Consumer
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.OfferSubscriptions_Client all

.PHONY: OfferSubscriptions_Server
OfferSubscriptions_Server: OfferSubscriptions_Idl OfferSubscriptions_Consumer
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.OfferSubscriptions_Server all

project_name_list:
	@echo OfferSubscriptions_Client
	@echo OfferSubscriptions_Consumer
	@echo OfferSubscriptions_Idl
	@echo OfferSubscriptions_Server
