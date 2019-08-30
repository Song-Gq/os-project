#include <stdio.h>

long atol(const char *nptr)
{
        int c;              /* current char */
        long total;         /* current total */
        int sign;           /* if '-', then negative, otherwise positive */

        /* skip whitespace */
        while ((int)(unsigned char)*nptr == ' ')
            ++nptr;

        c = (int)(unsigned char)*nptr++;
        sign = c;           /* save sign indication */
        if (c == '-' || c == '+')
            c = (int)(unsigned char)*nptr++;    /* skip sign */

        total = 0;

        while (c >= 48 && c <= 57) {
            total = 10 * total + (c - '0');     /* accumulate digit */
            c = (int)(unsigned char)*nptr++;    /* get next char */
        }

        if (sign == '-')
            return -total;
        else
            return total;   /* return result, negated if necessary */
}

int atoi(const char *nptr)
{
        return (int)atol(nptr);
}

int main(int argc, char * argv[])
{
	int player = 0,
		winner = 0,
		choice = 0;
	unsigned int row = 0,
		column = 0;
	char board[3][3] = {
		{'1', '2', '3'},
		{'4', '5', '6'},
		{'7', '8', '9'}
	};

	//Game loop
	for (unsigned int i = 0; i < 9 && winner == 0; i++)
	{
		//Dispaly the board.
		printf("\n"
			" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
		printf("---+---+---\n"
			" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
		printf("---+---+---\n"
			" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);

		//Select player.
		player = i % 2 + 1;

		//Get player's selection.
		do
		{
			printf("Player %d, please enter a valid sqare number "
				"for where you want to place your %c: ",
				player, (player == 1) ? 'X' : 'O');
			char buffer[128];
			read(0, buffer, 128);
			choice = atoi(buffer);

			row = --choice / 3;
			column = choice % 3;
		} while (choice < 0 || choice > 8 || board[row][column] > '9');

		//Insert player symbol.
		board[row][column] = (player == 1) ? 'X' : 'O';

		//Check for a winning line.
		if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
			(board[0][2] == board[1][1] && board[0][2] == board[2][0]))
			winner = player;
		else
		{
			for (unsigned int line = 0; line < 3; ++line)
			{
				if ((board[line][0] == board[line][1] && board[line] == board[2]) ||
					(board[0][line] == board[1][line] && board[0][line] == board[2][line]))
					winner = player;
			}
		}
	}
	
	//Game is over so display the final board.
	printf("\n"
		" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
	printf("---+---+---\n"
		" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
	printf("---+---+---\n"
		" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);

	//Display result message.
	if (winner)
		printf("\nCongratulations, player %d, YOU ARE THE WINNER!\n", winner);
	else
		printf("How boring, it's a draw.\n");

	return 0;
}
