function solution(tickets) {
  const answer = [];
  const adjAirport = {};
  const usedTicket = new Array(tickets.length).fill(false);

  tickets.sort(([aFrom, aTo], [bFrom, bTo]) => {
    if(aFrom !== 'ICN' && bFrom !== 'ICN') {
      if(aFrom === bFrom) return aTo < bTo ? -1 : 1;
      return aFrom < bFrom ? -1 : 1;
    } else {
      if(aFrom === bFrom) return aTo < bTo ? -1 : 1;
      return aFrom === 'ICN' ? -1 : 1;
    }
  });

  tickets.forEach(ticket => {
    const [from, to] = ticket;
    from in adjAirport
      ? adjAirport[from].push(to)
      : adjAirport[from] = [to];
  });

  const dfs = (from, tJourney) => {
    if(tJourney.length === tickets.length + 1) {
      answer.push([...tJourney]);
      return true;
    }

    tickets.forEach(([depart, arrive], index) => {
      if(from == depart && !usedTicket[index]) {
        tJourney.push(arrive);
        usedTicket[index] = true;
        
        if(dfs(arrive, tJourney)) return true;
        
        usedTicket[index] = false;
        tJourney.pop();
      }
    });
  };

  dfs('ICN', ['ICN']);
  return answer[0];
}