number = 23
running = True

while running:
    guess = int(raw_input('Enter an integer: '))

    if guess == number:
        print 'Congratulation, you guessed it.'
        running = False
    elif guess < number:
        print 'No, it is a little higher than it.'
    else:
        print 'No, it is a little lower than it.'
else:
    print 'The while loop is over.'

print 'Done.'
