CXX = cc
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = megaphone

SRCS = megaphone.cpp
OBJS = (SRCS:.cpp=.o)

all = $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean =
	rm -f $(OBJS)