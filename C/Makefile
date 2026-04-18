NAME = dr_quine_c

all:
	@$(MAKE) -C Colleen
	@$(MAKE) -C Grace
	@$(MAKE) -C Sully

clean:
	@$(MAKE) -C Colleen clean
	@$(MAKE) -C Grace clean
	@$(MAKE) -C Sully clean

fclean:
	@$(MAKE) -C Colleen fclean
	@$(MAKE) -C Grace fclean
	@$(MAKE) -C Sully fclean

re: fclean all

test: test_Colleen test_Grace test_Sully

test_Colleen:
	@$(MAKE) -C Colleen test

test_Grace:
	@$(MAKE) -C Grace test

test_Sully:
	@$(MAKE) -C Sully test

.PHONY: all clean fclean re test test_Colleen test_Grace test_Sully
