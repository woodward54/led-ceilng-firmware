const httpPrefix =
  process.env.NODE_ENV === 'development' ? 'http://192.168.1.172' : undefined;
export default httpPrefix;